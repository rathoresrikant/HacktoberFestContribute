import java.util.Scanner;
class Television
{
    private boolean pw,mt;
    private int vol,chn;
    public Television()
    {
        pw=mt=false;
        vol=3;
        chn=1;
    }

    public Television(boolean p,boolean m,int v,int c)
    {
        pw=p;
        mt=m;
        if(v>=0&&v<=10)
            vol=v;
        else
            vol=3;
        if(c>=1 && c<=99)

            chn=c;
        else
            chn=1;
    }

    public void power()
    {
        if(pw==true)

            pw=false;
        else
            pw=true;
    }

    public void mute()
    {
        if(pw==false)
            return;
        mt=!mt;
    }

    public void volumeUp()
    {
        if(pw==false)
            return;
        else
        if(vol<10)
            vol++;
    }

    public void volumeDn()
    {
        if(pw==false)
            return;
        mt=false;
        if(vol>0)
            vol--;
    }

    public void channelUp()
    {
        if(!pw)
            pw=true;
        else
        {
            if(chn<99)
                chn++;
            else
                chn=1;
        }
    }

    public void channelDn()
    {
        if(!pw)
            pw=true;
        else
        {
            if(chn>1)
            {
                chn--;
            }
            else
                chn=99;
        }
    }

    public void channel(int c)
    {
        if(!pw)
            return;
        if(c>=1&&c<=99)
            chn=c;
        else
            System.out.println("Invalid channel");
    }

    public void show()
    {
        if(!pw)
        {
            System.out.println("TV is on");
        }
        else
        {
            System.out.println("TV is off");
            System.out.println("channel is in"+" "+chn);
            if(mt)
            {
                System.out.println("TV is muted");
            }
            else
            {

                System.out.println("volume is in"+" "+vol);
            }
        }
    }
        public static void main()
        {
            Television tv=new Television();
            tv.show();
            while(true)
            {
                System.out.println("1. Power on/off");
                System.out.println("2. Mute on/off");
                System.out.println("3. Voiume up");
                System.out.println("4. Volume down");
                System.out.println("5. Channel up");
                System.out.println("6. Channel down");
                System.out.println("7. Channel ");
                System.out.println("0. Exit");
                
                int ch;
                System.out.println("Enter your choice");
                Scanner sc=new Scanner(System.in);
                ch=sc.nextInt();
                if(ch==0)
                break;
                switch(ch)
                {
                    case 1:
                    tv.power();
                    break;
                    case 2:
                    tv.mute();
                    break;
                    case 3:
                    tv.volumeUp();
                    break;
                    case 4:
                    tv.volumeDn();
                    break;
                    case 5:
                    tv.channelUp();
                    break;
                    case 6:
                    tv.channelDn();
                    break;
                    case 7:
                    int c;
                    System.out.println("Enter your choice");
                    c=sc.nextInt();
                    tv.channel(c);
                    break;
                    default:
                    System.out.println("Wrong Choice");
                }
                
                    tv.show();
                
                }
            }
        }
