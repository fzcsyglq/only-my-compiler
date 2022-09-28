int work() {
    return 3;
}
int main() {
    //int a[1][2][3]={1,2,3,4};
    int a[100] = {1,2,3,4};
    float b[100] = {1,2,3};
    int x = 0;
    int y = 1;
    int z = 2;
    int u = a[x+y+z];
    a[x+y+z] = 100;
    return 0;
}
