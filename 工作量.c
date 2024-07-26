#include <stdio.h>

enum
{
	N = 5000+10, 
} ;

typedef
struct
{
	int t , d , p ;	//花费时间 截止时间 报酬 
} GZ;

void sr(GZ[],int) ;
int qiu_max(int , int) ;
int bijiao(const void*,const void*) ;
int qiu_zdbc(GZ[],int) ;

int main(void)
{
    int zs ;
    scanf("%d",&zs);
    while ( zs -- > 0 )
    {
        int sl ;		//待完成工作数量 
        scanf("%d",&sl) ;
        GZ gz[N] ; 
        sr(gz,sl) ; 

        //按截至时间
		qsort(gz, sl, sizeof(gz[0]), bijiao) ;

        printf("%d\n",qiu_zdbc(gz,sl)) ;
    }
    return 0 ;
}

int qiu_zdbc(GZ gz[],int sl)
{
        int bc[N]={0} ;	 //记报酬 
        int i  ;
        for ( i = 0 ; i < sl ; i ++ )
        {
            int j ;
            for ( j = gz[i].d ; j >= gz[i].t ; j -- )
            {
                bc[j] = qiu_max(bc[j] , bc[j-gz[i].t]+gz[i].p) ;
            }
        }

        int max = 0 ;
        for ( i = 0 ; i < N ; i ++ )
        {
            max = qiu_max(max,bc[i]) ;
        }
    
        return max;     
}

int bijiao(const void* qv, const void* hv)
{
	const GZ * q = qv ;
	const GZ * h = hv ;
	return (q->d) - (h->d) ;
}

int qiu_max(int a, int b)
{
	return a > b ? a : b ;
}

void sr(GZ a[],int n)
{
	int i ;
	for ( i = 0 ; i < n ; i ++ )
	{
		scanf("%d%d%d",&a[i].t,&a[i].d,&a[i].p) ;
	}
}









