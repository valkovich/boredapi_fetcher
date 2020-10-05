# Test task

Assignment: C++ Cross Platform

Problem Statement:  Create a library in C++ that retrieves activities from the Bored API.  Fetch the values from the server and provide a response in JSON format to the caller.  Additionally add functionality to create and delete created activities (local storage only, not server) that can be utilized by a front end.

Requirements for success:

1. - [X] C++ layer: fetch activities from the API
2. - [X] C++ layer: add and delete activities in local storage
3. Create 3 frontends (very simple one screen)
   1. iOS , 1 screen to display activities, both fetched and local, 1 screen to create an activity
   2. Android 1 screen to display activities, both fetched and local, 1 screen to create an activity
   3. React JS 1 screen to display activities, both fetched and local, 1 screen to create an activity

Note: the UI frontend is only to demonstrate how the native platform code, ie: swift, Kotlin/java & javascript interact with the C++ code that is written.

#### Repo will be updated tommorow.

What's missed in library: 1) data validation 2) tests 3) documentation 4) closing of all TODOes.

##Multiplatform
- [Scapix](https://www.scapix.com) will be used. It can automatically create bridge files for  all platforms.
It converts C++ data types to Kotlin, OBJ C, JS data types. And also it perfectly fits in CMake projects. So, I use the following algorithm to build a portable library.

1. Creating an idiomatic C++ working draft of a library 
2. Looking at list of compatible types. And writing an API for a library.

And CMake will make the all the rest work for me. It will generate static lib files and launch Scapix, that will remade .h files. 


##Resources:

[https://www.boredapi.com/documentation]: https://www.boredapi.com/documentation	"API Docs"

Sample Query:

http://www.boredapi.com/api/activity/

Response:

```
{
	"activity": "Learn Express.js",
	"accessibility": 0.25,
	"type": "education",
	"participants": 1,
	"price": 0.1,
	"link": "https://expressjs.com/",
	"key": "3943506"
} 
```

### Tested on
- [X] Linux (Ubuntu 19.04)
- [ ] Windows
- [X] MacOS

### Requirements
   
   #### Linux and MacOS
       If you are running UNIX based system. 
       Run "prepare.sh" and it will install vcpkg with needed packages.
       
       $ chmod +x prepare.sh
       $ ./prepare.sh
       $ mkdir build
       $ cd build
       $ cmake 
           
#### Build Requirements
- [CMake](https://cmake.org/)
- [VCPKG](https://github.com/microsoft/vcpkg)
