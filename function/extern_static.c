
// static global variable can only be accessed by
// the function within the same source file
static float pi = 3.14;

float getPi(){
    return pi;
}

float area(float radius){
    return 2*pi*radius;
}