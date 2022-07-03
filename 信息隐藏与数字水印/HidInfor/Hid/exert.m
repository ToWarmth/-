clc;
clear all;
wi = imread('huntermarked.bmp');%��������ͼ��
[row col] =size(wi);
watermarklen =24;%Ƕ���ˮӡ��Ϣ�ĳ���
l1 = floor(row/watermarklen);%����ͼ��ֿ��ĳ���
l2 = floor(col/watermarklen);%����ͼ��ֿ��Ŀ��
pixelblack(1,watermarklen)=0;%ĳһ���ֿ��к�ɫ���صĸ���
pixelwhite(1,watermarklen)=0;%ĳһ���ֿ��а�ɫ���صĸ���
n = 1;
while n <=watermarklen
for i = l1* (n -1)+1:l1* n
for j = l2* (n -1)+1:l2* n
if wi(i , j ) ==0
pixelblack(1,n) = pixelblack(1,n)+1;%����ÿ���ֿ��еĺ�ɫ���صĸ���
else
pixelwhite(1,n) = pixelwhite(1,n)+1;%����ÿ���ֿ��еİ�ɫ���صĸ���
end
end
end
n = n + 1;
end
n =1;
while n<= watermarklen
if pixelwhite(1,n) >pixelblack(1,n)%�����ɫ���ؿ���ں�ɫ���ؿ�,������ϢΪ1
message(n,1)= 1;
else
message(n,1)=0;%�����ɫ���ؿ���ڰ�ɫ���ؿ�,������ϢΪ0
end
n =n +1;
end
% msgfid = fopen( 'hidden.txt' , 'r');
% [ msg , count ] = fread(msgfid);
% fclose(msgfid);
% msg = str2bit(msg);
% message= msg';
message
%����ȡ��������Ϣת�����ַ���
out = bit2str(message);
fid = fopen('message.txt' , 'wt');
fwrite(fid,out);
fclose(fid);
