#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
int source, destination;
char buffer[100];
int n;
source = open("source.txt", O_RDONLY);
if(source < 0)
{
printf("Source file cannot be opened\n");
exit(1);
}
destination = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
if(destination < 0)
{
printf("Destination file cannot be opened\n");
close(source);
exit(1);
}
while((n = read(source, buffer, sizeof(buffer))) > 0)
{
write(destination, buffer, n);
}
close(source);
close(destination);
printf("File copied successfully\n");
return 0;
}
