clc;
clear all;
msgfid = fopen( 'hidden.txt ' , 'r');%�������ļ�
[ msg,count ] = fread(msgfid);
fclose(msgfid);
msg = dec2bin(msg)
str='';
for i=1:4
    str=strcat(str,dec2bin(msg(i)));
end
msg = str;
count = count* 8;
io = imread( 'PIC1.jpg');%��������ͼ��
watermarklen = count;%Ƕ��ˮӡ��Ϣ����,Ҳ��������ͼ��ֿ������ֵ
[ row col ] =size(io);
l1 = floor(row/watermarklen);%����ͼ��ֿ��ĳ���
l2 = f1oor(col/watermarklen);%����ͼ��ֿ��Ŀ��
pixelcount = l1*12;%ÿ���ֿ������ص�����ֵ
percent = ceil(pixelcount/2 );
iw = io;
ioblack( 1 ,watermarklen)=0;%ĳһ���ֿ��к�ɫ���صĸ���
iowhite(1,watermarklen) =0;%ĳһ���ֿ��а�ɫ���صĸ���
n = 1;
while n <= watermarklen
for i = l1* (n -1)+1:11* n
    for j = 12* (n -1)+1:12* n
        if io(i ,j)==0
ioblack(1 ,n) = ioblack(1,n)+1;%����ÿ���ֿ��еĺ�ɫ���صĸ���
        else
            iowhite(l,m) =iowhite(1 ,n)+1;%����ÿ���ֿ��е�̨ɫ���صĸ���end
        end
    end
    end
    n=n+1;
end
    n =1;
while n <= watermarklen
if msg(m,1)==1%��ҪǶ��1
if ioblack(1,n)>= percent ;%Ƕ��1��ʱ��,��ɫ���رȰ�ɫ���ض�,��Ҫ�޸�һЩ���ص���ɫ
modcount(l ,m)= ioblack(ll.n) - percent +l;
k =1;
for i=l1* (n-1)+1:ll*n
for j=l2* (n-1)+1:12*n
if (iw( i ,j ) == 1&&k <= modcount(1,n))
iw( i , j)=0;k =k +1;
end
end
end
end
end
n =n + 1;
end
n=1;
iwblack(1, watermarklen)=O;%ĳһ���ֿ��к�ɫ���صĸ���iwwhite(1,wat ermarklen)=0;%ĳһ���ֿ��а�ɫ���صĸ���while n< = watermarklen
for i = l1* (n -1)+1:11* n
    for j = 12* (n-1)+1:12* n
        if iw( i , j ) ==0
iwblack(1,n) = iwblack(1 ,n)+1;%����ÿ���ֿ��еĺ�ɫ���صĸ���else
iwwhite(1,n) = iwwhite(1,n)+1;%����ÿ���ֿ��еİ�ɫ���صĸ���end
end
    end
    n = n +1;
end
figure;
imshow( 'hunter.bmp' );
imwrite( iw ,'huntermarked.bmp' );
figure;
imshow( 'huntermarked.bmp ' );


