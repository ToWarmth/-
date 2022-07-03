clc;
clear all;
msgfid = fopen( 'hidden.txt' , 'r');%�������ļ�

[msg,count] = fread(msgfid);
fclose(msgfid);
msg = str2bit(msg);
msg = msg';
count = count * 8;
io = imread('PIC1.jpg');%��������ͼ��
subplot(2,2,1)     
imshow( io );
io=rgb2gray(io);     %������x���лҶȴ���
subplot(2,2,2)     %�������в����У��ڶ���ͼ
imshow(io);         %����Ҷ�ͼ��
io=imbinarize(io,0.65); %��תΪ��ֵͼ�񣬶�ֵ����ֵΪ0.65
subplot(2,2,3)     %�������в����У�������ͼ
imshow(io)        %����ڰ׶�ֵͼ��
watermarklen = count;%Ƕ��ˮӡ��Ϣ����,Ҳ��������ͼ��ֿ������ֵ
[row,col] = size(io);
l1=floor(row/watermarklen);%����ͼ��ֿ��ĳ���
l2= floor(col/watermarklen);%����ͼ��ֿ��Ŀ��
pixelcount = l1* l2;%ÿ���ֿ������ص�����ֵ
percent = ceil(pixelcount/2);
iw = io;
ioblack(1,watermarklen)=0;%ĳһ���ֿ��к�ɫ���صĸ���
iowhite(1,watermarklen)=0;%ĳһ���ֿ��а�ɫ���صĸ���
n= 1;
while n<=watermarklen
for i = l1* (n -1)+1:l1* n
for j = l2* (n - 1)+1:l2* n
if io( i ,j )==0
ioblack(1, n)= ioblack(1 , n)+1;%����ÿ���ֿ��еĺ�ɫ���صĸ���
else
iowhite(1 ,n)= iowhite(1,n)+1;%����ÿ���ֿ��еİ�ɫ���صĸ���
end
end
end
n = n +1;
end
n = 1;
while n<=watermarklen
if msg(n, 1) ==1 %��ҪǶ��1
if ioblack(1,n)>=percent %Ƕ��1��ʱ��,��ɫ���رȰ�ɫ���ض�,��Ҫ�޸�һЩ���ص���ɫ
modcount(1,n)=ioblack(1,n)-percent + 1;
k = 1;
for i = l1* (n-1 )+1:l1* n
for j = l2* (n -1)+1:l2* n
if (iw( i ,j) ==0&&k <= modcount(1,n))
iw( i , j )=1;k =k+1;
end
end
end
end
else
if iowhite(1,n) >=percent %Ƕ��0��ʱ��,��ɫ���ر��ɫ���ض�,��Ҫ�޸�һЩ���ص���ɫ
modcount (1,n) = iowhite(1,n) - percent + 1;
k = 1;
for i = l1* (n -1)+1:l1* n
for j = l2* (n-1)+1:l2* n
if (iw(i , j )== 1&&k <= modcount(1,n))
iw( i , j)=0;k =k +1;
end
end
end
end
end
n=n + 1;
end
n=1;

iwblack(1 ,watermarklen)=0;%ĳһ���ֿ��к�ɫ���صĸ���
iwwhite( 1,watermarklen)=0;%ĳһ���ֿ��а�ɫ���صĸ���
while n <= watermarklen
for i = l1* (n -1)+ 1:l1* n
for j = l2* (n-1)+1:l2* n
if iw( i , j) ==0
iwblack(1,n) = iwblack(1,n)+1;%����ÿ���ֿ��еĺ�ɫ���صĸ���
else
iwwhite(1,n)= iwwhite(1,n)+1;%����ÿ���ֿ��еİ�ɫ���صĸ���
end
end
end
n=n + 1;
end

imwrite(iw,'huntermarked.bmp' );
%figure;
subplot(2,2,4)
imshow( 'huntermarked.bmp' );