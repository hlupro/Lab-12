# Lab-12

#Using this program

When using this input type ./lab12 "filename.txt" with the name of your txt file.

#How to format your text file

The very first line will be false because the graph is undirected.
The next line will be a line of integers separated by one space and serve as the vertices of the graph.
The remaining lines form a pattern and come in pairs, lines 1 and lines 2. The first line will be a singular
integer that corresponds to a vertex in the graph, the second line will be another series of integers one space
apart that serves as the adjacency list for the vertex above it. This two line pairing adds edges to the graph.
Since the graph is undirected do not double count edges, only include the edge under the first vertex. For example,
when adding the adjacency list for vertex 1 and 3 which are neighbors You would include 3 under vertex 1 but you wouldn't include 1 under 3

Example input

false
1 2 3 4 5 6
1
2
2
3 6
3
5
4
5
5
6 7

#Questions

#Summarize your approach to the problem and how your code addresses the abstractions needed.

For this lab, I decided to make use of the the pair container found in the std library when creating an edge map. Since the metadata for an edge map would include the number of the edge followed by its two vertices that the edge connects it would be more efficient to use a pair than to do a map of a map. By creating an edge map I can then easily delete edges from a copy of the map when finding a vertex cover. Finding a vertex cover involves taking the edge list, which is made during construction and then creating a copy of it and having a while loop run until that edge map copy is empty. Thee loop picks the first edge in the map and adds its vertices to a list container s and then deletes every edge that is connected to the vertices. If there is only one edge left, it inserts the first vertex in the pair.
randomVertexCover works the same way except before an edge is selected all the edge numbers are copied into a vector that is the size of the edge map at the time which then using rand() to get a number from 0-size-1 which is the index. Then an iterator is set to the edge located at vector[i] using the find function.

#Find and provide some specific graph instances where the computed cover is always sub optimal.

      1-----2
        \   |
          \ |
    4-------3
            |
            |
            5

    Edges numbered 1-4 top to left right top to bottom

    This graph will always be suboptimal as the algorithm will take the vertices 1,2,3,4 when 3 is the minimum for a vertex cover.

#For what graph structures is the algorithm close to optimal? Far from it?

I believe its closer to optimal on graphs that are cyclic and contain many cycles as the changes of finding a vertex that
has many edges is higher than that of an acyclic graph.

#How could the code be improved in terms of usability, efficiency and robustness?
The algorithms will never find a vertexCover of size 1 due to adding the pair of vertices instead of one. This could perhaps be remedied with a search function that checks if its a proper vertexCover before inserting the second vertex. But then even the change of that is completely dependent on how each edge is numbered. If the first edge that is numbered is connected to vertex that has many edges the vertex cover will be smaller and vice versa.
