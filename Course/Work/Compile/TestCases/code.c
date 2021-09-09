void empty();
int instancesDeclarations( int a );
void longExpr();
void calls();
void conditions( int a, int b, int c, int d, int e, int g );
void cycles();
void ternOperator( int t );

void empty(){}
/*
 * sda
 * asd
 * asda
 * sdsad
 * */
int instancesDeclarations( int a )
{
    static char A = 1, B = 2, C = 3, D = 4 ;
    double n = 1.0, y, gdsfg, fgsdfg, dsfgsdfg, dfgsdsfg_, fg = 45.4f , dddddd;
    int a, b = A + B << C / D + 123 - 32482374 , c;
    const char t = A + B + C + dddddd;

    return a;
}

/*
 * asdasdasdasd
 *  dsad asd
 * sadasdasdasdasdasd
 * */


inline int foo( int t ) { return ++t; }

// asdasdasdasdasdasdasdsa


void longExpr()
{
    int a, b, c, d;
    a = ( a + b );
    a = a + b / c << ( d % a ) + ( ++d ) + ( c-- ) / ( 8 & 3 | a ) + (1-2) / 11 + a;
    return a + b * c << d / (a + 11 + 2 + (b+c));
}

//sd asd asd asdsadasdasdas

void calls()
{
    int p = 0;
    int pp[ 10 ];

    pp[ 0 ] = 1;
    pp[ p ] = 1;

    // asdasdasdas d\
    sadsadasdds \
    sadasdasddasd

    calls();
    calls( p );
    calls( 1 );
    calls( 1, 2, 3 );
    calls( 1, p, p + p * p, p + 1);
    calls( calls( ) );
    calls( 1, p, p + p * p, p + 1, calls( p ) );
    calls( calls( calls( calls( p ) ), 1 + p ) );

    calls( pp[ 1 ] );
    calls( pp[ p ] );
}


void conditions( int a, int b, int c, int d, int e, int g )
{
    if (a) foo(b);

    if ( a > b )
    {
        foo( a );
    }
    else if ( a < c + 1 )
    {
        foo( 2 );
    }
    else if ( b > c )
    {
        foo( b );
    }
    else
        foo( foo( a ) + foo( b ) );
    if ( a )
        if ( b )
            if ( c )
                foo ( c );


    if ( a && b < c || a - 1 == 2 || a == 3 && b - a * 2 > 3 || a != 2 )
    {
        foo(a);
    }
}

void cycles()
{
    int a = 0;
    int b = 0;
    int c = 0;

    while ( ( a + b - c == d - 1 && ( 1 << 2 % 2 ) ) && foo( 2 ) || (1 > 2) && (2<1) )
        a++;

    while ( ( a + b - c == d - 1 && ( 1 << 2 % 2 ) ) && foo( 2 ) || (1 > 2) && (2<1) )
    {
        a++;
        b++;
        c++;
    }

    int A[ 100 ], B[ 100 ], C[ 100 ];
    for ( int i = 0; i < 100; ++i )
    {
        A[ i ] = 0;
        B[ i ] = 0;
        C[ i ] = 0;
    }

    for ( int i = 0; i < 100; ++i )
        C[i] = A[     i  ] + B[i];

    do { } while ( --a );
}

void ternOperator( int t )
{
    foo( t > 5 ? 1 : 2 );

    return t < 3 ? foo( 3 ) : foo( 1 );
}
