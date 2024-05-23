# Course_Work_OOP

**Description** of the program WebGraph_v2 in the attached file _Description.pdf_ .

**Remark**:
There aree two versions: WebGraph_v1 & WebGraph_v2.
First program executes better its task (also it has ability to zoom and move graph by buttons, good visualization, it is faster).
Second made to fully meet requirements of the course work (however the image of graph is not the best).

**Important**: while testing, to avoid overload, please enter as input the link to some website that is not big and which is not refers to big websites.

**Video of WebGraph_v1 executing**:
https://youtu.be/9Rs2dZJP1QY

**Video of WebGraph_v2 executing**:
https://youtu.be/J-_Q2QoS83Q



To compile and execute, I used these commands (first navigate to corresponding folder WebGraph):

For WebGraph_v1:

g++ -std=c++14 -o bin/graphexec src/main.cpp src/HTML_FETCHER.cpp src/vertex.cpp src/null_depth.cpp src/first_depth.cpp src/second_depth.cpp src/third_depth.cpp -Iinclude -Iinclude/gumbo -Llib -Wl,-rpath,lib -lsfml-graphics -lsfml-window -lsfml-system -lgumbo -lcurl

./bin/graphexec

For WebGraph_v2:

g++ -std=c++14 -o bin/graphexec src/main.cpp src/HTML_FETCHER.cpp src/FirstDepthNode.cpp src/SecondDepthNode.cpp src/ThirdDepthNode.cpp src/PageNode.cpp src/RootNode.cpp -Iinclude -Iinclude/gumbo -Llib -Wl,-rpath,lib -lsfml-graphics -lsfml-window -lsfml-system -lgumbo -lcurl

./bin/graphexec
