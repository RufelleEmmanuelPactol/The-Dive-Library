#define struct_freelist __global__memory__struct__
#define pointers __ptr__private__memory__
#define freelist __internal__freelist__memory
#define EXPLICIT __explicit__enum__identifier__
#define exception_memory __exception__out__of__memory__
#define zero_alloc __exception__allocation__of__size__zero__
#include <map>
#include <vector>
using std::size_t;
#include <iostream>



/**
 * Supported functions:
 * allocate (void * ptr) - safer malloc
 * reallocate (void * ptr, size_t new_size) - safer realloc
 * release (void * ptr) - safer free
 * release (void * ptr, EXPLICIT warning_level) - less safer free, more explicit
 * sizeOf (void * ptr) - proper sizeOf function for pointers
 * garbage_collector () - deallocates all unnecessary memory taken up by the freelist
 * gc_trash_load() - returns the size of the memory taken up by the garbage collector
 * is_released() - returns a boolean and checks whether if a memory pointer has been released
 */
namespace dive {

    class exception_memory : public std::exception {};
    class zero_alloc : public std::exception{};

    struct struct_freelist {
        std::map<void*, size_t>  * pointers;

        struct_freelist(){
            pointers = new std::map<void*, size_t>();
        }

        ~struct_freelist(){
            delete pointers;
        }

        void DoubleFree(){
            std::cerr << "[Double Free]: In dive::release, occurred instance of double freeing memory.\n";
            throw exception_memory();
        }

        void OutOfMemory(){
            throw exception_memory();
        }

        void UnknownInstance(void * instance){
            std::cerr << "[Unknown Pointer]: In dive::release, specified pointer with address '" << instance << "' not allocated with dive::malloc.\n";
            throw exception_memory();
        }

        void AllocZero(){
           throw zero_alloc();
        }

    };

    // global instance
    struct_freelist * freelist = new struct_freelist();

    /**
     * @warning Do not use this method! Deleting this method can possibly result in memory leaks.
     * @return Returns true if the free list was deleted.
     */
    bool delete_freelist(){
        delete freelist;
        return true;
    }


    // proper methods


    /**
     * @brief Returns the total amount allocated using the dive_memory module.
     * @return The size of all memory allocated in bytes.
     */
    size_t total_alloc(){
        size_t mem_sum = 0;
        for (auto &i : *freelist->pointers){
            mem_sum += i.second;
        } return mem_sum;
    }

    /**
     *
     * @param size Specifies the amount of memory to allocate in bytes.
     * @return Returns a void* which needs to be typecast to the appropriate type.
     */
    void* allocate (size_t size){
        if (!size) freelist->AllocZero();
        void* temp = std::malloc(size);
        if (temp==NULL) freelist->OutOfMemory();
        freelist->pointers->emplace(temp, size);
        return temp;
    }

    /**
     * @warning The returned value must be stored or else, a memory leak will occur.
     * @param ptr The pointer to the memory to reallocate.
     * @param new_size The new size to allocate in bytes.
     * @return A void* with the heap-allocated memory.
     */
    void* reallocate (void * ptr, size_t new_size){
        auto it = freelist->pointers->find(ptr);
        if (it==freelist->pointers->end()) freelist->UnknownInstance(ptr);
        std::pair<void*, size_t> emplace_pair;
        auto temp = realloc(ptr, new_size);
        if (temp==NULL) freelist->OutOfMemory();
        emplace_pair.first = temp;
        emplace_pair.second = new_size;
        freelist->pointers->emplace(emplace_pair);
        it->second = 0;
        return temp;
    }

    /**
     * @warning Upon calling this method, all memory released before the invocation of this method will be cleared from the cache. Calling release(<released_ptr>) again on pointers released prior to the function call, even under safe mode, will not be recognized by release() and [Unknown Pointer] will be invoked.
     * @brief Removes all the freed memory from the dive::freelist, removes overhead.
     * @return Returns the number of empty buckets freed.
     */
    size_t garbage_collector (){
        auto temp = freelist->pointers;
        std::vector<std::pair<void*, size_t>> remove_list;
        for (auto &i: *temp) if (!i.second) remove_list.emplace_back(i);
        for (auto &i : remove_list) temp->erase(i.first);
        return remove_list.size();
    }


    enum EXPLICIT{
        Safe, Explicit
    };

    /**
     *
     * @param ptr The pointer to free.
     * @return Returns true if the pointer was successfully freed. If the pointer was already freed, to avoid double free, returns false instead.
     */
    bool release (void * ptr){
        auto it = freelist->pointers->find(ptr);
        if (it==freelist->pointers->end()) freelist->UnknownInstance(ptr);
        if (!it->second) return false;
        std::free(ptr);
        it->second = 0;
        return true;
    }

    /**
     *
     * @param ptr The pointer to free.
     * @param warning_level Specified the warning level of the release() function. If warning is dive::Explicit, can possibly throw double free to cache-stored values. If dive::Safe was used, if the function was freed beforehand, returns false instead of an error.
     */
    bool release (void * ptr, EXPLICIT warning_level){
        if (warning_level==Safe) return release(ptr);
        auto it = freelist->pointers->find(ptr);
        if (it==freelist->pointers->end()) freelist->UnknownInstance(ptr);
        if (it->second == 0) freelist->DoubleFree();
        std::free(ptr);
        it->second = 0;
        return true;
    }

    size_t sizeOf(void * ptr){
        auto iterator = freelist->pointers->find(ptr);
        if (iterator == freelist->pointers->end()) freelist->UnknownInstance(ptr);
        return iterator->second;
    }

    /**
     *
     * @return The approximate (not 100% accurate) amount of memory used up by the garbage collector's caching system in bytes.
     */
    size_t gc_trash_load(){
        constexpr size_t constant_sizes = sizeof(std::pair<void*, size_t>);
        auto len = freelist->pointers->size();
        return len * constant_sizes;
    }

    bool is_released(void * ptr){
        auto a = freelist->pointers->find(ptr);
        if (a==freelist->pointers->end()){
            freelist->UnknownInstance(ptr);
        } return !(a->second);
    }


}

#undef struct_freelist
#undef pointers
#undef freelist
#undef EXPLICIT
#undef exception_memory
#undef zero_alloc
