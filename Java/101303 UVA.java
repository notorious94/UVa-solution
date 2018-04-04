import java.math.BigInteger;
import java.util.*;
public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        BigInteger T[] = new BigInteger[1001];
        T[0] = T[1] = BigInteger.ONE;
        for(int i=2;i<=1000;i++)
        {
            T[i] = BigInteger.ZERO;
            for (int j=0;j<i;j++)
                T[i] = T[i].add(T[j].multiply(T[i-j-1]));
        }
        while (sc.hasNext())
        {
            int n = sc.nextInt();
            System.out.println(T[n]);
        }
        System.exit(0);
    }
}
