int instancesDeclarations( int a )
{
    static char A = 1, B = 2, C = 3, D = 4 ;
    double n = 1.0, y, gdsfg, fgsdfg, dsfgsdfg, dfgsdsfg_, fg = 45.4f , dddddd;
    int a, b = A + B << C / D + 123 - 32482374 , c;
    const char t = A + B + C + dddddd;

    return a;
}

inline int foo( int t ) { return ++t; }

void longExpr()
{
    int a, b, c, d;
    a = ( a + b );
    a = a + b / c << ( d % a ) + ( ++d ) + ( c-- ) / ( 8 & 3 | a ) + (1-2) / 11 + a;
    return a + b * c << d / (a + 11 + 2 + (b+c));
}

void conditions( int a, int b, int c, int d, int e, int g )
{
    if ( a > b )
    {
        foo( a );
    }
    else if ( b > c )
    {
        foo( b );
    }
    else ( a && b < c || a - 1 == 2 || a == 3 && b - a * 2 > 3 || a != 2 )
        foo( foo( a ) + foo( b ) );
    if ( a )
        if ( b )
            if ( c )
                foo ( c );
}
