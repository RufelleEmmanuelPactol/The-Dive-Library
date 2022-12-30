# Dive-Framework-Fulcrum-Array
Dive Framework's Fulcrum Array data structure. Allows for O(1) head and tail inserts and removes, maximum of O(log n) middle-of-array operations and O(n) resizes.


## Big O notation

### Inserts:

O(1) - add at head, add at tail

Worst case: O(log n) - add at areas outside of head and tail

### Removes:

O(1) - remove at head, remove at tail

Worst case: O(log n) - remove at areas outside of head and tail

### Resizes:

O(n) - if array reduces or increases capacity

### Access operations:

O(1) - standard index access 

### Space complexity:

Worst case: O(2n)

Best case: O(n)

