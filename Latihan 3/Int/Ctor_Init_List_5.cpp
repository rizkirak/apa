class Node
{
public:
    Customer obj;
    Node(string,char,int);
}
and then define the Node constructor like this in your .cpp file:

Node :: Node(string x,char y,int z) : obj(x, y, z) {

}
