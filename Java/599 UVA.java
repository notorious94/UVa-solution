import java.util.*;
public class Main
{
    public static int[] rank = new int[26];
    public static int[] parent = new int[26];
    static int Find(int a)
    {
        if(a==parent[a])
            return a;
        else
        {
            parent[a] = Find(parent[a]);
            return parent[a];
        }
    }
    static boolean makePair(int a,int b)
    {
        int u = Find(a);
        int v = Find(b);
        if(u==v)    return false;
        if(rank[u]>=rank[v])
        {
            rank[u]+=rank[v];
            parent[v] = parent[u];
        }
        else
        {
            rank[v]+=rank[u];
            parent[u] = parent[v];
        }
        return true;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s;
        int test;
        int[] edge1 = new int [100000];
        int[] edge2 = new int [100000];
        test = sc.nextInt();
        for (int k = 1; k <= test; k++)
        {
            int c = 0;
            while (true)
            {
                s = sc.next();
                if(s.charAt(0)=='*')    break;
                edge1[c] = s.charAt(1)-'A';
                edge2[c] = s.charAt(3)-'A';
                c++;
            }
            s = sc.next();
            int ancor = 0,tree = 0;
            for(int i=0;i<s.length();i+=2)
            {
                tree++;
                int a = s.charAt(i)-'A';
                parent[a] = a;
                rank[a] = 1;
            }

            for (int i=0;i<c;i++)
                if (makePair(edge1[i],edge2[i]))
                    tree--;

            for (int i=0;i<s.length();i+=2)
                if(rank[Find(s.charAt(i)-'A')]==1)
                    ancor++;
            System.out.printf("There are %d tree(s) and %d acorn(s).\n",tree-ancor,ancor);
        }
        System.exit(0);
    }
}
