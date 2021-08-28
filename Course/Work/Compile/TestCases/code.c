int foo ( int a )
{
    static char A = 1, B = 2, C = 3, D = 4 ;

    int a, b, c;

    return a;
}

int bar( int t )
{
    int a, b, c, d = 1, e, f, g = 5, h, i, j, k, l;
    int u = t + 1 - 23 & 1 && 2 | 2 || a << b >> c < k;

    return u;
}

void foo_bar_1( int a, double b, unsigned char c )
{
    bar( a );
}
