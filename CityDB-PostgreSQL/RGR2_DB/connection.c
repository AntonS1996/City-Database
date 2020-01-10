/* Processed by ecpg (4.12.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "D:\\RGR2_DB\\RGR2_DB\\connection.txt"

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

#line 1 "D:\\RGR2_DB\\RGR2_DB\\connection.txt"

    // Подключение к базе данных (данный для входа)
    /* exec sql begin declare section */ 
            
            
            
    
#line 4 "D:\\RGR2_DB\\RGR2_DB\\connection.txt"
 char ConnectionString [] = "cities@localhost:5432" ;
 
#line 5 "D:\\RGR2_DB\\RGR2_DB\\connection.txt"
 char Login [] = "postgres" ;
 
#line 6 "D:\\RGR2_DB\\RGR2_DB\\connection.txt"
 char Password [] = "qwert" ;
/* exec sql end declare section */
#line 7 "D:\\RGR2_DB\\RGR2_DB\\connection.txt"


int connectToDB() {
    { ECPGconnect(__LINE__, 0, ConnectionString , Login , Password , NULL, 0); }
#line 10 "D:\\RGR2_DB\\RGR2_DB\\connection.txt"

    if( sqlca.sqlcode != 0 || strncmp(sqlca.sqlstate,"00",2))
        {
            return -1;
            // printf("Проблемы с подключением с базой данных \n");
            // exit(-1);
        }
    return 0;
    // printf("База данных подключена \n");	
}

int disconnectFromDB() {
    { ECPGdisconnect(__LINE__, "CURRENT");}
#line 22 "D:\\RGR2_DB\\RGR2_DB\\connection.txt"

    // printf("Успешное отключение от базы данных \n");
    return 0;
}

void readStringFromConsole(char str[256]) {
	scanf("%c", str);
	str[0] = '\0';
	scanf("%[ a-zA-Z0-9+,а-яА-Я/-.:]", str);
}

void error1()
{
	printf("Возникли ошибки при выполнении инструкции\n");
}

void error2()
{
	printf("Предупреждение при выполнении инструкции\n");
}

void error3()
{
	printf("Данных для дальнейшего вывода не найдено \n");
}
