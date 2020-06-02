#include "triangle.hpp"

Triangle::Triangle(Vertex& v1, Vertex& v2, Vertex& v3)
 : mVertex1(v1), mVertex2(v2), mVertex3(v3)
{

}

Triangle::~Triangle()
{

}

Vertex Triangle::getVertex1()
{
    return mVertex1;
}

Vertex Triangle::getVertex2()
{
    return mVertex2;
}

Vertex Triangle::getVertex3()
{
    return mVertex3;
}

