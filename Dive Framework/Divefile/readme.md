# Dive's FileReader Library

This library aims to make CPP file handling easier, mirroring JAVA's FileReader and FileWriter classes. These classes are RAII compliant to ensure memory leaks are avoided.

## FileReader

Has the following methods:

readLine();

readFile();

resetFile();

isOpen();

close();

get();


## FileWriter

Has the following methods:

writeLine();

writeFile(vector);

writeFile(vector, delimiter);

setAppend();

isAppend();

isOpen();

close();

flush();
