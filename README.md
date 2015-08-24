#XML Generation Tool

##1. Purpose

The Tool `dtd_generation/gendtd.cpp` is the C++ App that will automatically generate the XML file for you when you provide the objective data to it. This will help you easily create XML files and Docs that are ready to use

##2. Making the Tool

This guide suppose that you already have GCC-C++ compiler installed.



```sh
cd dtd_generation/
g++ gendtd.cpp -o gendtd

```

This will create an executable file `gendtd`.

To execute the same simple :

```sh
./gendtd
```

or

```sh
./gendtd <new-file-name>.xml
```

#TODO :

Reading a formatted file and automatically take the file as input and generate the required XML file. This will enable BATCH processing very easy.
