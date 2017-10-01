
import java.math.BigDecimal;  
import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);  
		int T = in.nextInt();
		BigDecimal x1,x2,x3,y1,y2,y3,x,y;
        while(T-- > 0)  
        {  
        	x1 = in.nextBigDecimal();
        	y1 = in.nextBigDecimal();
        	x2 = in.nextBigDecimal();
        	y2 = in.nextBigDecimal();
        	x3 = in.nextBigDecimal();
        	y3 = in.nextBigDecimal();
        	x = in.nextBigDecimal();
        	y = in.nextBigDecimal();
        	/*
        	 * 圆心坐标（a，b），半径为r，点(x,y)
        	 *	a = ((y2-y1)*(y3*y3-y1*y1+x3*x3-x1*x1) - (y3-y1)*(y2*y2-y1*y1+x2*x2-x1*x1))/(2.0*((x3-x1)*(y2-y1)-(x2-x1)*(y3-y1)));
				b = ((x2-x1)*(x3*x3-x1*x1+y3*y3-y1*y1) - (x3-x1)*(x2*x2-x1*x1+y2*y2-y1*y1))/(2.0*((y3-y1)*(x2-x1) - (y2-y1)*(x3-x1)));
				r^2 = (x1-a)*(x1-a) + (y1-b)*(y-b);
        	 */
        	
        	
        	BigDecimal a1 = (y2.subtract(y1)).multiply(y3.multiply(y3).subtract(y1.multiply(y1)).add(x3.multiply(x3)).subtract(x1.multiply(x1)));
        	BigDecimal a2 = (y3.subtract(y1)).multiply(y2.multiply(y2).subtract(y1.multiply(y1)).add(x2.multiply(x2)).subtract(x1.multiply(x1)));
        	BigDecimal a3 = BigDecimal.valueOf(2.0).multiply(((x3.subtract(x1)).multiply(y2.subtract(y1))).subtract((x2.subtract(x1)).multiply(y3.subtract(y1))));
        	BigDecimal a = (a1.subtract(a2)).divide(a3);
        	
        	BigDecimal b1 = (x2.subtract(x1)).multiply(x3.multiply(x3).subtract(x1.multiply(x1)).add(y3.multiply(y3)).subtract(y1.multiply(y1)));
        	BigDecimal b2 = (x3.subtract(x1)).multiply(x2.multiply(x2).subtract(x1.multiply(x1)).add(y2.multiply(y2)).subtract(y1.multiply(y1)));
        	BigDecimal b3 = BigDecimal.valueOf(2.0).multiply(((y3.subtract(y1)).multiply(x2.subtract(x1))).subtract((y2.subtract(y1)).multiply(x3.subtract(x1))));
        	BigDecimal b = (b1.subtract(b2)).divide(b3);
        	//半径
        	BigDecimal r2 = (x1.subtract(a)).multiply(x1.subtract(a)).add((y1.subtract(b)).multiply(y1.subtract(b)));
        	//到圆心的距离
        	BigDecimal sum = (x.subtract(a)).multiply(x.subtract(a)).add((y.subtract(b)).multiply(y.subtract(b)));
        	if(sum.compareTo(r2) > 0)//到圆心距离大于等于半径
        		System.out.println("Accepted");
        	else
        		System.out.println("Rejected");
        }
	}
}