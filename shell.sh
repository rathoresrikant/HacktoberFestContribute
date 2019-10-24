# this only works on Unix systems
# recursively prints all files in the current directory
#!/bin/bash

for f in `find .`;
do
    echo $f
done
