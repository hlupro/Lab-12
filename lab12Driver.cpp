#include "graph.h"

int main(int argc, char *argv[]) {
    std::ifstream inFile;
    inFile.open(argv[1]);
    if(inFile) {
      Graph test(inFile);
      test.printEdges();
      std::cout << "Testing deterministic vertex cover." << std::endl;
      test.vertexCover();
      std::cout << "Testing random vertex cover." << std::endl;
      test.randomVertexCover();
    }
    else {
      std::cout << "File failed to open." << std::endl;
    }
    inFile.close();

}
