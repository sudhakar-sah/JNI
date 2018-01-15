public class HelloJNI {
    static {
      System.loadLibrary("hello");// load native library at runtime 
      }

    // Declare a native method sayHello() that receives nohing and retuns void 
    
    static int n1 = 10; 
    static int n2 = 20; 
    static private String str1 = "from Java"; 
    
    private native String sayHello(int n1, int n2, String str1);

    private native double[] sumAndAverage(int[] numbers); 
 

    //Test driver 
    public static void main(String[] args) {
      //String str2 = new HelloJNI().sayHello(n1, n2, str1);// invoke the native method  
      //System.out.print("Printing from Java : ");
      //System.out.print("this string came from C : "); 
      //System.out.println(str2);

    	int[] numbers = {22,33,33}; 
    	double[] results = new HelloJNI().sumAndAverage(numbers); 
    	System.out.println("In Java, computed from C sum is :" + results[0]); 
    	System.out.println("In Java, computed from C average is :" + results[0]); 
    		
    }
} 


