clc;
clear all;
close all;
n=input('Enter the number of disk schedules:');
input_order=input('Enter the queue of disk schedules:');
curr_pos=input('Enter the current position of disk head:');


[A_HEURISTIC,order1]=heuristic(n,input_order,curr_pos);
figure(1);
subplot(2,2,1);
plotting(order1,n);
title('Heuristic');

[A_PRIORITY,order6]=priority(n,input_order,curr_pos);
figure(1);
subplot(2,2,2);
plotting(order6,n);
title('PRIORITY');

[A_MHFS,order7]=mhfs(n,input_order,curr_pos);
figure(1);
subplot(2,2,3);
plotting(order7,n);
title('MHFS');

[A_ODSA,order2]=odsa(n,input_order,curr_pos);
figure(1);
subplot(2,2,4);
plotting(order2,n);
title('ODSA');

[A_FCFS,order3]=fcfs(n,input_order,curr_pos);
figure(2);
subplot(2,3,1);
plotting(order3,n);
title('FCFS');

[A_SSTF,order4]=sstf(n,input_order,curr_pos);
figure(2);
subplot(2,3,2);
plotting(order4,n);
title('SSTF');

[A_SCAN,order5]=scan(n,input_order,curr_pos);
figure(2);
subplot(2,3,3);
plotting_scan(order5,n);
title('SCAN');

[A_LOOK,order8]=look(n,input_order,curr_pos);
figure(2);
subplot(2,3,4);
plotting(order8,n);
title('LOOK');

[A_C_SCAN,order9]=c_scan(n,input_order,curr_pos);
figure(2);
subplot(2,3,5);
plotting_c_scan(order9,n);
title('C-SCAN');

[A_C_LOOK,order10]=c_look(n,input_order,curr_pos);
figure(2);
subplot(2,3,6);
plotting(order10,n);
title('C-LOOK');


function plotting(final_order,n)
x=[0:1:n];
axis([0 n+1 0 200]);
hold on;
plot(x,final_order)
hold on;
plot(x,final_order,'bo')
grid on;
end

function plotting_scan(final_order,n)
x=[0:1:n+1];
axis([0 n+2 0 200]);
hold on;
plot(x,final_order)
hold on;
plot(x,final_order,'bo')
grid on;
end

function plotting_c_scan(final_order,n)
x=[0:1:n+2];
axis([0 n+3 0 200]);
hold on;
plot(x,final_order)
hold on;
plot(x,final_order,'bo')
grid on;
end

function [a,s1]=heuristic(n,order,curr_pos)
asc_order=sort(order);
disp(asc_order);
left=asc_order(n)-curr_pos;
right=curr_pos-asc_order(1);
count=1;
final_order=zeros(1,n+1);
final_order(1)=curr_pos;
% syms markup markdown;
for i=1:n
    if asc_order(i)>=curr_pos
            markup=i;
            markdown=i-1;
            break;
    end
end
seek=zeros(1,n);

if left < right
    for i=markup:n
        seek(count)=asc_order(i)-curr_pos;
        curr_pos=asc_order(i);
        count=count+1;
        final_order(count)=asc_order(i);
    end
    for i=markdown:-1:1
        seek(count)=curr_pos-asc_order(i);
        curr_pos=asc_order(i);
        count=count+1;  
        final_order(count)=asc_order(i);
    end
elseif right <= left
        for i=markdown:-1:1
        seek(count)=curr_pos-asc_order(i);
        curr_pos=asc_order(i);
        count=count+1; 
        final_order(count)=asc_order(i);
        end   
        for i=markup:n
        seek(count)=asc_order(i)-curr_pos;
        curr_pos=asc_order(i);
        count=count+1;
        final_order(count)=asc_order(i);
        end
end
sum=0;
for i=1:n
    sum=sum+seek(i);
end
%disp(seek)
disp('Heuristic Final Order is')
disp(final_order)
disp('Heuristic Seek is')
disp(sum);
%disp(HEURISTIC);
s1=final_order;
a=sum;
end

function [a,s2]=odsa(n,order,curr_pos)

asc_order=sort(order);
disp(asc_order);
left=asc_order(n)-curr_pos;
right=curr_pos-asc_order(1);
count=1;
%syms markup markdown;
for i=1:n
    if asc_order(i)>=curr_pos
            markup=i;
            markdown=i-1;
            break;
    end
end
seek=zeros(1,n);
final_order=zeros(1,n+1);
final_order(1)=curr_pos;
if left < right
    for i=n:-1:1
        final_order(n-i+2)=asc_order(i);
        seek(n-i+1)=abs(final_order(n-i+1)-asc_order(i));
    end
elseif right <= left
        for i=1:n
            final_order(i+1)=asc_order(i);
            seek(i)=abs(final_order(i)-asc_order(i));
        end
end
sum=0;
for i=1:n
    sum=sum+seek(i);
end
disp('ODSA Final Order is')
disp(final_order)
disp('ODSA Seek is')
disp(sum);
s2=final_order;
a=sum;
end

function [a,s3]=fcfs(n,order,curr_pos)

sum=0;
sum=sum+abs(curr_pos-order(1));
for i=1:n-1
    diff=abs(order(i)-order(i+1));

    sum=sum+diff;
end
final_order=zeros(1,n+1);
final_order(1)=curr_pos;
for i=2:n+1
    final_order(i)=order(i-1);
end
disp('FCFS Final Order is')
disp(final_order)
disp('FCFS Seek is')
disp(sum)
s3=final_order;
a=sum;
end

function [a,s4]=sstf(n,order,curr_pos)
sum=0;
final_order=zeros(1,n+1);
final_order(1)=curr_pos;
m=n;
disp(m);
for k=1:m
    diff=zeros(1,n);
    index=zeros(1,n);
    for i=1:n
        diff(i)=abs(curr_pos-order(i));
        index(i)=i;
    end
    for i=1:n
        for j=i:n
            if diff(j)<diff(i)
                temp=diff(i);
                temp2=index(i);
                diff(i)=diff(j);
                index(i)=index(j);
                diff(j)=temp;
                index(j)=temp2;
            end
        end
    end
    sum=sum+diff(1);
    curr_pos=order(index(1));
    final_order(k+1)=curr_pos;
    order(index(1))=[];
    n=n-1;
    if n==0
        disp('breaking')
        break;
    end
end
disp('sstf')
disp(final_order)
disp('seek')
SSTF=sum;
disp(SSTF);
s4=final_order;
a=sum;
end

function [a,s5]=scan(n,order,curr_pos)
last=input('Enter disk size: ');
last=last-1;
sum=0;
final_order=zeros(1,n+2);
final_order(1)=curr_pos;
count=2;
order=sort(order);
for i=1:n
    if order(i)>curr_pos
        mark1=i;
        mark2=i-1;
        break;
    end
end
if(abs(order(mark1)-curr_pos)>abs(order(mark2)-curr_pos))
    for i=mark2:-1:1
        final_order(count)=order(i);
        count=count+1;
        sum=sum+abs(curr_pos-order(i));
        curr_pos=order(i);
    end
    sum=sum+curr_pos;
    curr_pos=0;
    final_order(count)=0;
    count=count+1; 
    for i=mark1:n
        final_order(count)=order(i);
        count=count+1;
        sum=sum+abs(order(i)-curr_pos);
        curr_pos=order(i);
    end
elseif(abs(order(mark1)-curr_pos)<abs(order(mark2)-curr_pos))
    for i=mark1:n
        final_order(count)=order(i);
        count=count+1;
        sum=sum+abs(order(i)-curr_pos);
        curr_pos=order(i);
    end
    sum=sum+last-curr_pos;
    curr_pos=last;
    final_order(count)=curr_pos;
    count=count+1;    
    for i=mark2:-1:1
        final_order(count)=order(i);
        count=count+1;
        sum=sum+abs(curr_pos-order(i));
        curr_pos=order(i);
    end
end
disp('scan')
disp(final_order)
disp('seek')
disp(sum)
s5=final_order;
a=sum;
end

function [a,s6]=priority(n,order,curr_pos)
priority_order=input("Enter the priority of schedulling: ")
sum=0;
final_order=zeros(1,n+1);
final_order(1)=curr_pos;
for i=1:n
    for j=i:n
        if priority_order(j)<priority_order(i)
            temp=priority_order(i);
            temp2=order(i);
            priority_order(i)=priority_order(j);
            order(i)=order(j);
            priority_order(j)=temp;
            order(j)=temp2;
        end
    end
end
for i=1:n
    final_order(i+1)=order(i);
end
for i=1:n
    sum=sum+abs(curr_pos-order(i));
    curr_pos=order(i);
end 
disp('priority')
disp(final_order)
disp('seek')
disp(sum)
s6=final_order;
a=sum;
end

function [a,s7]=mhfs(n,order,curr_pos)
order=sort(order);
final_order=zeros(1,n+1);
final_order(1)=curr_pos;
sum=0;
count=2;
for i=1:n
    if order(i)>curr_pos
        mark=i-1;
        break;
    end
end
if mark>=n/2
    for i=mark:-1:1
        sum=sum+curr_pos-order(i);
        final_order(count)=order(i);
        count=count+1;
        curr_pos=order(i);
    end
    for i=mark+1:n
        sum=sum+order(i)-curr_pos;
        final_order(count)=order(i);
        count=count+1;
        curr_pos=order(i);
    end
end
if mark<n/2
    for i=mark+1:n
        sum=sum+order(i)-curr_pos;
        final_order(count)=order(i);
        count=count+1;
    end
    for i=mark:-1:1
        sum=sum+curr_pos-order(i);
        final_order(count)=order(i);
        count=count+1;
        curr_pos=order(i);
    end
end
disp('MHFS')
disp(final_order)
disp('Seek')
disp(sum)
a=sum;
s7=final_order;
end

function [a,s8]=look(n,order,curr_pos)
sum=0;
final_order=zeros(1,n+1);
final_order(1)=curr_pos;
count=2;
order=sort(order);
for i=1:n
    if order(i)>curr_pos
        mark1=i;
        mark2=i-1;
        break;
    end
end
if(abs(order(mark1)-curr_pos)>abs(order(mark2)-curr_pos))
    for i=mark2:-1:1
        final_order(count)=order(i);
        count=count+1;
        sum=sum+abs(curr_pos-order(i));
        curr_pos=order(i);
    end 
    for i=mark1:n
        final_order(count)=order(i);
        count=count+1;
        sum=sum+abs(order(i)-curr_pos);
        curr_pos=order(i);
    end
elseif(abs(order(mark1)-curr_pos)<abs(order(mark2)-curr_pos))
    for i=mark1:n
        final_order(count)=order(i);
        count=count+1;
        sum=sum+abs(order(i)-curr_pos);
        curr_pos=order(i);
    end
    for i=mark2:-1:1
        final_order(count)=order(i);
        count=count+1;
        sum=sum+abs(curr_pos-order(i));
        curr_pos=order(i);
    end
end
disp('look')
disp(final_order)
disp('seek')
disp(sum)
s8=final_order;
a=sum;
end

function [a,s9]=c_scan(n,order,curr_pos)
last=input('Enter disk size: ');
last=last-1;
sum=0;
final_order=zeros(1,n+3);
final_order(1)=curr_pos;
count=2;
order=sort(order);
for i=1:n
    if order(i)>curr_pos
        mark1=i;
        mark2=i-1;
        break;
    end
end
if(abs(order(mark1)-curr_pos)>=abs(order(mark2)-curr_pos))
    for i=mark2:-1:1
        final_order(count)=order(i);
        count=count+1;
        sum=sum+curr_pos-order(i);
        curr_pos=order(i);
    end
    sum=sum+curr_pos;
    curr_pos=0;
    final_order(count)=curr_pos;
    count=count+1;
    curr_pos=last;
    final_order(count)=curr_pos;
    count=count+1;
    for i=n:-1:mark1
        sum=sum+curr_pos-order(i);
        curr_pos=order(i);
        final_order(count)=curr_pos;
        count=count+1;
    end
elseif(abs(order(mark1)-curr_pos)<abs(order(mark2)-curr_pos))
    for i=mark1:n
        final_order(count)=order(i);
        count=count+1;
        sum=sum+abs(order(i)-curr_pos);
        curr_pos=order(i);
    end
    sum=sum+last-curr_pos;
    curr_pos=last;
    final_order(count)=curr_pos;
    count=count+1;
    curr_pos=0;
    final_order(count)=curr_pos;
    count=count+1;
    for i=1:mark2
        final_order(count)=order(i);
        count=count+1;
        sum=sum+abs(curr_pos-order(i));
        curr_pos=order(i);
    end
end
sum=sum+199;
disp('c_scan')
disp(final_order)
disp('seek')
disp(sum)
s9=final_order;
a=sum;
end

function [a,s10]=c_look(n,order,curr_pos)
sum=0;
final_order=zeros(1,n+1);
final_order(1)=curr_pos;
count=2;
order=sort(order);
for i=1:n
    if order(i)>curr_pos
        mark1=i;
        mark2=i-1;
        break;
    end
end
if(abs(order(mark1)-curr_pos)>=abs(order(mark2)-curr_pos))
    for i=mark2:-1:1
        final_order(count)=order(i);
        count=count+1;
        sum=sum+abs(curr_pos-order(i));
        curr_pos=order(i);
    end
    for i=n:-1:mark1
        sum=sum+abs(curr_pos-order(i));
        curr_pos=order(i);
        final_order(count)=curr_pos;
        count=count+1;
    end
elseif(abs(order(mark1)-curr_pos)<abs(order(mark2)-curr_pos))
    for i=mark1:n
        final_order(count)=order(i);
        count=count+1;
        sum=sum+abs(order(i)-curr_pos);
        curr_pos=order(i);
    end
    for i=1:mark2
        final_order(count)=order(i);
        count=count+1;
        sum=sum+abs(curr_pos-order(i));
        curr_pos=order(i);
    end
end
disp('c_look')
disp(final_order)
disp('seek')
disp(sum)
s10=final_order;
a=sum;
end

