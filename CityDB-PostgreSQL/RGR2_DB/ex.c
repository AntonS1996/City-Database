/* Processed by ecpg (4.12.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"
/*
ecpg prog1.pgc
cc -I/usr/include/pgsql -c ex.c
cc -o ex ex.o -L/usr/lib64 -lecpg,,
где -L/usr/local/pgsql/lib путь где лежит libecpg.so
-I/usr/local/pgsql/include путь где лежит ecpgtype.h, ecpglib.h, ecpgerrno.h, sqlca.h.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#line 1 "D:/Program Files/PostgreSQL/9.6/include/sqlca.h"
#ifndef POSTGRES_SQLCA_H
#define POSTGRES_SQLCA_H

#ifndef PGDLLIMPORT
#if  defined(WIN32) || defined(__CYGWIN__)
#define PGDLLIMPORT __declspec (dllimport)
#else
#define PGDLLIMPORT
#endif   /* __CYGWIN__ */
#endif   /* PGDLLIMPORT */

#define SQLERRMC_LEN	150

#ifdef __cplusplus
extern		"C"
{
#endif

struct sqlca_t
{
	char		sqlcaid[8];
	long		sqlabc;
	long		sqlcode;
	struct
	{
		int			sqlerrml;
		char		sqlerrmc[SQLERRMC_LEN];
	}			sqlerrm;
	char		sqlerrp[8];
	long		sqlerrd[6];
	/* Element 0: empty						*/
	/* 1: OID of processed tuple if applicable			*/
	/* 2: number of rows processed				*/
	/* after an INSERT, UPDATE or				*/
	/* DELETE statement					*/
	/* 3: empty						*/
	/* 4: empty						*/
	/* 5: empty						*/
	char		sqlwarn[8];
	/* Element 0: set to 'W' if at least one other is 'W'	*/
	/* 1: if 'W' at least one character string		*/
	/* value was truncated when it was			*/
	/* stored into a host variable.             */

	/*
	 * 2: if 'W' a (hopefully) non-fatal notice occurred
	 */	/* 3: empty */
	/* 4: empty						*/
	/* 5: empty						*/
	/* 6: empty						*/
	/* 7: empty						*/

	char		sqlstate[5];
};

struct sqlca_t *ECPGget_sqlca(void);

#ifndef POSTGRES_ECPG_INTERNAL
#define sqlca (*ECPGget_sqlca())
#endif

#ifdef __cplusplus
}
#endif

#endif

#line 12 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

//#pragma comment(lib, "libecpg.lib")
         /*
                EXEC SQL BEGIN DECLARE SECTION;
                EXEC SQL END DECLARE SECTION; - пара инструкций для обьявления переменных,
                которые будут взаимодействовать с данными на сервере.
                Внутри этих инструкций используется обычный С-синтаксис обьявления и
                            инициализации переменных
            */

        //для соединения с БД
        /* exec sql begin declare section */ 
            
            
            
        
#line 24 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"
 char ConnectionString [] = "testDB@localhost:5433" ;
 
#line 25 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"
 char Login [] = "postgres" ;
 
#line 26 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"
 char Password [] = "1" ;
/* exec sql end declare section */
#line 27 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"


        //для взаимодействия с БД
        /* exec sql begin declare section */
                 
                 
                 
                 
                  
              
#line 31 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"
 int my_id ;
 
#line 32 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"
 char my_data [ 256 ] ;
 
#line 33 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"
 int my_count ;
 
#line 34 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"
 char date1 [ 10 ] ;
 
#line 35 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"
 char date2 [ 10 ] ;
/* exec sql end declare section */
#line 36 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"
	

        /*
                Инструкция, позволяющая обрабатывать ошибки.
        */
        //void f_error(void);
        //EXEC SQL WHENEVER SQLERROR CALL f_error;	
        /* exec sql whenever sqlerror  sqlprint ; */
#line 43 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"
			
        /*
            Общий синтаксис: 
            EXEC SQL WHENEVER condition action;
                condition - тип ошибок, который будет отлавливаться.
                action - действие, которое будет инициироваться при возникновении ошибки
                Возможные значения condition:
                                 SQLERROR - ошибки при выполении инструкции
                                 SQLWARNING -  предупреждения при выполении инструкции
                                 NOT FOUND - попытка извлечь пустую строку
              Возможные значения action:   
                                 CONTINUE - продолжение работы приложения	
                                 GOTO label - переход на метку
                                 SQLPRINT - печать ошибок в стандартный поток ошибок
                                 STOP - эквивалент exit(1) в С
                                 DO BREAK - эквивалент break в С. Используется только в switch
                                            или в цикле.
                                 CALL name (args) - вызов функции name с аргументами args 
                                 DO name (args)   - вызов функции name с аргументами args 

        */
int menu();
int Dynamic_sql_insert();
int Dynamic_sql_select_1();
int Dynamic_sql_select_2();
int InsertValues();
int ReadAllRecord();
int SelectValues();
int UpdateValues();
int DeleteValues();

int main() {

        { ECPGconnect(__LINE__, 0, ConnectionString , Login , Password , NULL, 0); 
#line 76 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 76 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"


                /*
                   Переменная sqlca - структура. Поле sqlcode - можно использовать для 
                   индикации ошибок. 
                   sqlstate - переменная из 5 символов. Если первые два 00, то всё нормально
                */

        if( sqlca.sqlcode != 0 || strncmp(sqlca.sqlstate,"00",2))
        {
                printf("connect -- NoOK\n");
                exit(-1);
        }
        else
        {
                printf("connect --OK\n");	
                menu();
        }	
        { ECPGdisconnect(__LINE__, "CURRENT");
#line 94 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 94 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

        printf("disconnect --OK\n");
}

int menu()
{
        char sitem[512];
        while(1)
        {
            printf("1. show\n");
            printf("2. select values\n");
            printf("3. update values\n");
            printf("4. insert values\n");
            printf("5. delete values\n");
            printf("6. Dynamic sql insert\n");
            printf("7. Dynamic sql select one\n");
            printf("8. Dynamic sql select more than one\n");
            printf("9. quit\n");
            printf("choose menu item > ");
            if(scanf("%s", &sitem)!=1) break;
         
if (strlen(sitem)>1) continue;   
           
                switch(sitem[0])
                {
                        case '1':
                        {
                                printf("_____________________\n");
                                printf("1. show\n");
                                ReadAllRecord();
                                printf("_____________________\n");
                                break;
                        }
                        case '2':
                        {
                                printf("_____________________\n");
                                printf("2. select values\n");
                                SelectValues();
                                printf("_____________________\n");
                                break;
                        }
                        case '3':
                        {
                                printf("_____________________\n");
                                printf("3. update values\n");
                                UpdateValues();
                                printf("_____________________\n");
                                break;
                        }
                        case '4':
                        {
                                printf("_____________________\n");
                                printf("4. insert values\n");	
                                InsertValues();
                                printf("_____________________\n");
                                break;
                        }
                        case '5':
                        {
                                printf("_____________________\n");
                                printf("5. delete values\n");
                                DeleteValues();
                                printf("_____________________\n");
                                break;
                        }
                        case '6':
                        {
                               Dynamic_sql_insert();
                               break;
                        }
                        case '7':
                        {
                               Dynamic_sql_select_1();
                               break;
                        }
                         case '8':
                        {
                               Dynamic_sql_select_2();
                               break;
                        }
                        case '9':
                        {
                                return 0;
                        }
                        default: break;
                }
        }
        return 0;
}

int Dynamic_sql_insert()
{
/* exec sql begin declare section */ 
       
  
        
#line 188 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"
 char stmt [] = "INSERT INTO exTab(id,name) VALUES(?, ?);" ;
/* exec sql end declare section */
#line 189 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"


       { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select count ( * ) from exTab", ECPGt_EOIT, 
	ECPGt_int,&(my_count),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 191 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 191 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

        if(my_count==0)
        {	
                my_id=1;
        }
        else
        {
                { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select max ( id ) from exTab", ECPGt_EOIT, 
	ECPGt_int,&(my_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 198 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 198 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

                my_id=my_id+1;
        }

     

       { ECPGprepare(__LINE__, NULL, 0, "mystmt", stmt);
#line 204 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 204 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

 
       { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_execute, "mystmt", 
	ECPGt_int,&(my_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_const,"123",(long)3,(long)1,strlen("123"), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 206 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 206 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

       { ECPGtrans(__LINE__, NULL, "commit");
#line 207 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 207 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

        return 0;
}

int Dynamic_sql_select_1()
{
     /* exec sql begin declare section */           
             
             
                  
     
#line 214 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"
 char * stmt = "SELECT name " "  FROM exTab " "  WHERE id=?" ;
/* exec sql end declare section */
#line 217 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"




     { ECPGprepare(__LINE__, NULL, 0, "sqlstmt", stmt);
#line 221 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 221 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

     

    printf("select 'id' >");
        scanf("%d", &my_id);

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_execute, "sqlstmt", 
	ECPGt_int,&(my_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_char,(my_data),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 227 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 227 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

    printf("name=%s\n", my_data);	



    { ECPGtrans(__LINE__, NULL, "commit");
#line 232 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 232 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

    return 0;
}


int Dynamic_sql_select_2()
{
     /* exec sql begin declare section */           
             
             
             
      
      
     
#line 240 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"
 char * stmt = "SELECT name " "  FROM exTab " "  WHERE id>=? and id<=?" ;
 
#line 243 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"
 int id_min ;
 
#line 244 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"
 int id_max ;
/* exec sql end declare section */
#line 245 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"




     { ECPGprepare(__LINE__, NULL, 0, "sqlstmt", stmt);
#line 249 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 249 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"


     /* declare my_cursor cursor for $1 */
#line 251 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"


printf("select 'id_min' >");
        scanf("%d", &id_min);

printf("select 'id_max' >");
        scanf("%d", &id_max);

     { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare my_cursor cursor for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "sqlstmt", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(id_min),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(id_max),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 259 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 259 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"




     while (1)
     {
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch my_cursor", ECPGt_EOIT, 
	ECPGt_char,(my_data),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 265 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 265 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"
    
        if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2)) break;
        printf("name=%s\n", my_data);	
     }

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close my_cursor", ECPGt_EOIT, ECPGt_EORT);
#line 270 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 270 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"


    { ECPGtrans(__LINE__, NULL, "commit");
#line 272 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 272 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

    return 0;
}

int InsertValues()
{		
        /*
                Получения id
        */
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select count ( * ) from exTab", ECPGt_EOIT, 
	ECPGt_int,&(my_count),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 281 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 281 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

        if(my_count==0)
        {	
                my_id=1;
        }
        else
        {
                { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select max ( id ) from exTab", ECPGt_EOIT, 
	ECPGt_int,&(my_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 288 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 288 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

                my_id=my_id+1;
        }

       printf("enter new 'data' >");

        scanf("%c", my_data);
         
         my_data[0]='\0';
        scanf("%[ a-zA-Z0-9+,а-яА-Я/-.]",my_data);
        

       printf("enter new 'date1' >");
       
       scanf("%c", date1);
      
            date1[0]='\0';
        scanf("%[ a-zA-Z0-9+,а-яА-Я/-.]",date1);

 printf("enter new 'date2' >");
        scanf("%c", date2);
        
            date2[0]='\0';
        scanf("%[ a-zA-Z0-9+,а-яА-Я/-.]",date2);
        /*
                Вставка данных в таблицу из переменных my_id, my_data
        */
        
        
        
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into exTab ( id , name , date1 , date2 ) values ( $1  , $2  , $3  , $4  )", 
	ECPGt_int,&(my_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(my_data),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(date1),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(date2),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 318 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 318 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"


        /*
                Инструкция применения транзакции
                Если ошибок нет при выполении, то данные сохраняются в базе.
                Если произошла ошибка, то данные не сохраняются.
                !Так как по-умолчанию данные не сохраняются, то здесь
                нет необходимости явно писать инструкцию - EXEC SQL ROLLBACK,
                означающую откат транзакци
        */
        /*
                Применить транзакцию, т.е сохранить данные в базе.
        */
        { ECPGtrans(__LINE__, NULL, "commit");
#line 331 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 331 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

        return 0;
}


int ReadAllRecord()
{
        /*
                Обьявление курсора.
                Общий синтаксис: EXEC SQL DECLARE <cursor_name> CURSOR FOR <sql_statement>;
        */
        /* declare MyCursor cursor for select id , coalesce ( name , '' ) , coalesce ( cast ( date1 as varchar ) , '' ) , coalesce ( cast ( date2 as varchar ) , '' ) from exTab order by id */
#line 343 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

        /*
            Открытие курсора.
            Общий синтаксис: EXEC SQL OPEN <cursor_name>;
        */
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare MyCursor cursor for select id , coalesce ( name , '' ) , coalesce ( cast ( date1 as varchar ) , '' ) , coalesce ( cast ( date2 as varchar ) , '' ) from exTab order by id", ECPGt_EOIT, ECPGt_EORT);
#line 348 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 348 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

        while(1)
        {
            /*
                        Чтение из курсора.
                        Общий синтаксис: EXEC SQL FETCH <cursor_name> INTO <var_list>;,
                                   где <var_list> - список переменных	
            */
                { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch MyCursor", ECPGt_EOIT, 
	ECPGt_int,&(my_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(my_data),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(date1),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(date2),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 356 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 356 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"


                /*'ECPG_NOT_FOUND' - попытка прочитать пустую
               строку. */
                if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2)) break;		
                printf("\t %d \t %s \t %s \t %s\n", my_id, my_data, date1, date2);
        }
        /*
                Закрытие курсора.
                Общий синтаксис: EXEC SQL CLOSE <cursor_name>;
        */
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close MyCursor", ECPGt_EOIT, ECPGt_EORT);
#line 367 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 367 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

        { ECPGtrans(__LINE__, NULL, "commit");
#line 368 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 368 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

        return 0;
}

int SelectValues()
{		
        printf("select 'id' >");
        scanf("%d", &my_id);
        /*
                Извленеие данных из таблицы в переменные my_id, my_data
        */
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select id , name from exTab where id = $1 ", 
	ECPGt_int,&(my_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(my_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(my_data),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 379 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 379 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

        printf("id: %d, data: %s \n", my_id, my_data);
        return 0;
}
int UpdateValues()
{	
        printf("select updatable 'id' >");
        scanf("%d", &my_id);
        printf("enter new  'data' >");
        scanf("%s", my_data);

        /*
                Обновление данных data в таблице 
        */
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update exTab set name = $1  where id = $2 ", 
	ECPGt_char,(my_data),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(my_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 393 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 393 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"
	

        { ECPGtrans(__LINE__, NULL, "commit");
#line 395 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 395 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

        return 0;
}
int DeleteValues()
{
        printf("select deleted 'id' >");
        scanf("%d", &my_id);

        /*
                Удаление данных из таблицы
        */
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from exTab where id = $1 ", 
	ECPGt_int,&(my_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 406 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 406 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

        /*
                Применить транзакцию, т.е удалить данные из базы
        */
        { ECPGtrans(__LINE__, NULL, "commit");
#line 410 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 410 "D:\\RGR2_DB\\RGR2_DB\\ex.txt"

}
/*void f_error(void)
{
   printf("\n% .70s \n", sqlca.sqlerrm.sqlerrmc);
}*/
