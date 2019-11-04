# PRINT_TEXT_C
This is a program that prints the text you provide as an argument to the STDOUT; the text is colored!

## Makefile
Commads:

``` shell
> make
```
- creates the PRINT_N excutable + backup the files!

``` shell
> make NAME=<exec_name>
> make NAME=PROGRAM
```
- creates the excutable with a custom name!

``` shell
> make backup
```
- backups the files for restore if changes are made to the code!

``` shell
> make restore
```
- restores the files to their original version if a backup is present!

``` shell
> make clean
```
- cleans up the executable!
## Usage
For help page:
``` shell
>./PRINT_N
```
Basic usage:
``` shell
>./PRINT_N <Text>
```
Example:
``` shell
>./PRINT_N hakam
```
The above Command will output:
``` shell

   ##    ##     ##     ##    ##     ##     ##    ##
   ##    ##    ####    ##  ##      ####    ###  ###
   ########   ##  ##   ####       ##  ##   ## ## ##
   ##    ##  ########  ##  ##    ########  ##    ##
   ##    ##  ##    ##  ##    ##  ##    ##  ##    ##
```
Another example:
``` shell
>./PRINT_N "hakam 1337"
```
The above Command will output:
``` shell

   ##    ##     ##     ##    ##     ##     ##    ##
   ##    ##    ####    ##  ##      ####    ###  ###
   ########   ##  ##   ####       ##  ##   ## ## ##
   ##    ##  ########  ##  ##    ########  ##    ##
   ##    ##  ##    ##  ##    ##  ##    ##  ##    ##


   ####     ######   ######   #######
     ##          ##       ##      ##
     ##       ####     ####      ##
     ##          ##       ##    ##
   #######  ######   ######    ##
```
Usage with Colors:
``` shell
>./PRINT_N <Text> <color>
```
Example:
``` shell
>./PRINT_N "hakam 1337" red
```
The above Command will output:
![alt text](https://i.imgur.com/UAaO3cn.png)

## Supported Characters
Lowecase Alphabets:
``` shell
> a b c d e f g h i j k l m n o p q r s t u v w x y z
```
Uppercase Alphabets:
``` shell
> A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
```
Digits:
``` shell
> 0 1 2 3 4 5 6 7 8 9
```
Symbols:
``` shell
> . - _ ! ?
```

## Supported Colors
NB: Colors are CASE-INSENSITIVE; "red RED Red reD" :)
``` shell
> red green yellow blue cyan magenta
```
