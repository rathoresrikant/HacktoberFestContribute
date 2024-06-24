import java.util.*;
public class KeepMeAwake
{
  Thread t1;
  public void run()
  {
    System.out.println("I am not sleeping OK!!!");
  }
  public static void main(String args[])
  {
    t1 = new Thread();
    t1.start();
    t1.sleep(100000);
  }
}
