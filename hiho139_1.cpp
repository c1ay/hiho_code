#include <cstdio>
using namespace std;

int main()
{
  int T,n,i,j,k,b[55];
  double a[55];
  scanf("%d",&T);
  while(T--)
    {
      int w=0;
      scanf("%d",&n);
      for(i=0; i<n; i++)
        scanf("%lf%d",&a[i],&b[i]);
      for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
          for(k=j+1; k<n; k++)
            {
              double s=a[i]+a[j]+a[k];
              int x=b[i]+b[j]+b[k];
              int t=(int)s;
              if(s-t!=0)
                continue;
              if((int)s%5==0)
                {
                  if(w<x)
                    w=x;

                }
            }
      for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
          {
            double s=a[i]+a[j];
            int x=b[i]+b[j];
            int t=(int)s;
            if(s-t!=0)
              continue;
            if((int)s%5==0)
              {
                if(w<x)
                  w=x;
              }
          }
      for(i=0; i<n; i++)
        {
          int t=(int)a[i];
          if(a[i]-t!=0)
            continue;
          if((int)a[i]%5==0)
            {
              if(w<b[i])
                w=b[i];
            }
        }
      printf("%d\n",w);
    }
	return 0;
}
