# **ADT LinkedList**

## **Linked list** implemented as an ADT

> Source code can be found in the src directory

> Header files can be found in the include directory

**Installation**
------------

    git clone https://github.com/redyz13/adt_list

**Compile**
------------

    make

Each source file has a relative path of its header in the same directory.

If you want to compile the project without the make file remember to use the **gcc** flag:

    -Ipath_of_the_headers


Run *make clean* to clear object files and the output file

**Use your data**
------------

You can use whatever type of data you want by modifying the standard **item.c** and **item.h** files

The first thing that you wanna do is give the definition of item in **item.h** and modify the constant NULLITEM as an error value associated with your data

```c
// item.h

typedef int Item;

#define NULLITEM 0
```

In our example we're using a linked list of integers (look at the **main.c**)

After that you can change each function definition in **item.h** and each function body in **item.c**

All basic changes are indicated by a **"// TODO"** comment

**Deallocating your data in the list automatically**
------------

The list has some function that can deallocate your data in the heap when you remove a node or destroy the list

Those function are optional and commented by default because we're assuming that even by removing a node or deallocating the list you want to keep your data in memory

If you want to use those function you'll need to uncomment the lines indicated by a **"// XXX"** comment (they are present in the remove functions for the nodes in **node.c**)

Note that the **"// XXX"** comments for the *destroyList* in **list.c** and **list.h** are already uncommented as you can choose whether or not to use the function

After you have uncommented the lines, you'll need to change the body of the default function *freeItem* in **item.c**

The *freeItem* will also be used in the *destroyList* of **list.c**, so you can deallocate all your data

Example of a *freeItem* to deallocate a struct Person in the heap:

```c
// item.c

struct Person {
    char *name;
    char *surname;
    int age;
};

// Name and surname are also allocated in the heap

void freeItem(Item it) {
    free(it->name);
    free(it->surname);
    free(it);
}
```
