import java.lang.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main
{
    public static int lp[] = new int[1299710];
    public static int prime[] = new int[100000];
    static void sieve()
    {
        int size = 0;
        Arrays.fill(lp,0);
        for(int i=2;i<1299710;i++)
        {
            if(lp[i]==0)
            {
                lp[i] = i;
                prime[size++] = i;
            }
            for(int j=0;j<size&&prime[j]*i<1299710&&prime[j]<=i;j++)
                lp[i*prime[j]]=i;
        }
    }
    public static void gap()
    {
        lp[1] = 2;
        for(int i=0;i<100000-1;i++)
        {
            int a = prime[i],b = prime[i+1];
            int d = b-a;
            lp[a] = 0;
            lp[b] = 0;
            for(int j=a+1;j<b;j++)
                lp[j] = d;
        }
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        sieve();
        gap();
        int k;
        while (true)
        {
            k = sc.nextInt();
            if(k==0)    break;
            System.out.println(lp[k]);
        }
        System.exit(0);
    }
}
