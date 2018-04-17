import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextDouble())
        {
            double a = sc.nextDouble();
            double b = sc.nextDouble();
            double c = sc.nextDouble();

            double s = (a+b+c)*0.5;

            if(s==0.0000)
                System.out.printf("The radius of the round table is: 0.000\n");

            else
            {
                double area = Math.sqrt(s*(s-a)*(s-b)*(s-c));
                double r = area / s;
                System.out.printf("The radius of the round table is: %.3f\n",r);
            }
        }
        System.exit(0);
    }
}
