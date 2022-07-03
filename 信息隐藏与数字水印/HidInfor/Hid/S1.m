%��һ����ͼ��������ͨͼ����תΪ�Ҷ�ͼ����תΪ��ֵͼ��
clear all;clc;                %�������������
x=imread('PIC1.jpg');   %��ȡͼƬ
subplot(2,2,1)     %�������в����У���һ��ͼ
imshow(x);         %�����ɫͼ��
x=rgb2gray(x);     %������x���лҶȴ���
subplot(2,2,2)     %�������в����У��ڶ���ͼ
imshow(x);         %����Ҷ�ͼ��
xbw=imbinarize(x,0.65); %��תΪ��ֵͼ�񣬶�ֵ����ֵΪ0.65
subplot(2,2,3)     %�������в����У�������ͼ
imshow(xbw)        %����ڰ׶�ֵͼ��
imwrite(xbw,'PIC1_2.jpg');    %�����ֵͼ�񱣴�ΪPIC1_1.jpg
[m,n]=size(xbw)               %�����ֵͼ����������m������n
print(xbw,m,n)                %Insert֮ǰ�����
Insert(xbw,m,n);

function Insert(xbw,m,n)
x = abs('JUST');   %��Ƕ����ϢתΪ������������
str='';
for i=1:4
    str=strcat(str,dec2bin(x(i)))
end
x=str2num(str(:))
x=x.';                  %����ת��
j=1;
for i=1:m
    xbw(i,n)=x(j);
    j=j+1;
    if(j==28) break;
    end
end
print(xbw,m,n)
subplot(2,2,4);     %�������в����У�������ͼ
imshow(xbw);        %����ڰ׶�ֵͼ��
Decode(xbw,m,n);
end

function Decode(xbw,m,n)
y=zeros(1,28);
for i=1:m
    y(i)=xbw(i,n);
    if(i==28) break;
    end
end
y
str="";
for i=1:7:28
    num=y(i)*64+y(i+1)*32+y(i+2)*16+y(i+3)*8+y(i+4)*4+y(i+5)*2+y(i+6)
    temp=char(num)
    str=strcat(str,temp);
end
str
end

function to_0_percent = print(xbw,m,n)
counter_0=0;       %����counter_0���ڱ�ʾ��ɫ����(0)�ĸ���
counter_1=0;       %����counter_1���ڱ�ʾ��ɫ����(1)�ĸ���
for i=1:m          %��������鿴�ڰ����ص����
    for j=1:n
        if(xbw(i,j)==1) 
            counter_1=counter_1+1;
        end
        if(xbw(i,j)==0) 
            counter_0=counter_0+1;
        end 
    end
end
counter_0          %��������ص�(0)�ĸ���
counter_1          %��������ص�(1)�ĸ���
to_0_percent=counter_0/(counter_0+counter_1)     %��������ص�1��ռ��
end