int main () {
    int v[10], *pv = v;

    printf("%p\n" ,&v);
    printf("%p\n", pv);
    printf("%p\n" ,&v[0]);
    return 0;
}
