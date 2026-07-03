int mySqrt(int x) {
    if (x == 0) return 0;
    long r = x;
    while (r * r > x) {
        r = (r + x / r) >> 1; 
    }
    return (int)r;
}