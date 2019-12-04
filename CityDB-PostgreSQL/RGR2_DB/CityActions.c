/* Processed by ecpg (4.12.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"
/* exec sql begin declare section */
     
     
     
     
     

#line 2 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"
 char CITY_NAME [ 256 ] ;
 
#line 3 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"
 char REGION_CODE [ 256 ] ;
 
#line 4 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"
 char FOUNDATION_DATE [ 256 ] ;
 
#line 5 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"
 char CITY_POPULATION [ 256 ] ;
 
#line 6 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"
 char REGION_CODE_key [ 256 ] ;
/* exec sql end declare section */
#line 7 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"


/* exec sql whenever sqlerror  sqlprint ; */
#line 9 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"


int ReadCityTable();
int UpdateCityTable();
int InsertCityTable();
int DeleteCityTable();
int SelectCityTable();

void error1();
void error2();
void error3();

void readStringFromConsole(char str[256]);

int ReadCityTable() {
    printf("������� ������� \n");
	printf("%s \t %s \t %s \t %s \n", "�������� ������", "��� �������", "���� ���������", "���������");
	printf("_________________________________________________________________________________________________________\n");
    /* declare MyCursor cursor for select coalesce ( CITY_NAME , '' ) , coalesce ( REGION_CODE , '' ) , coalesce ( FOUNDATION_DATE , '' ) , coalesce ( CITY_POPULATION , '' ) from CITY order by CITY_NAME */
#line 28 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare MyCursor cursor for select coalesce ( CITY_NAME , '' ) , coalesce ( REGION_CODE , '' ) , coalesce ( FOUNDATION_DATE , '' ) , coalesce ( CITY_POPULATION , '' ) from CITY order by CITY_NAME", ECPGt_EOIT, ECPGt_EORT);
#line 29 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 29 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"
    
    while(1)
    {
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch MyCursor", ECPGt_EOIT, 
	ECPGt_char,(CITY_NAME),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(REGION_CODE),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(FOUNDATION_DATE),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_POPULATION),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 32 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 32 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

	if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2)) break;		
	printf("%s \t %s \t %s \t %s \n", CITY_NAME, REGION_CODE, FOUNDATION_DATE, CITY_POPULATION);
    }
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close MyCursor", ECPGt_EOIT, ECPGt_EORT);
#line 36 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 36 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

	/* exec sql whenever sqlerror  call error1 ( ) ; */
#line 37 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

	/* exec sql whenever sql_warning  call error2 ( ) ; */
#line 38 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

	/* exec sql whenever not found  call error3 ( ) ; */
#line 39 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 40 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 40 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 40 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

    printf("\n");
    return 0;
}

int UpdateCityTable() {
    /* exec sql begin declare section */
         
    
#line 47 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"
 char CITY_NAME_key [ 256 ] ;
/* exec sql end declare section */
#line 48 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

	printf("������� �������� ������ � ����� ������ ��� ����: \n ");
    printf("�������� ������ > ");
    readStringFromConsole(CITY_NAME_key);
    
    printf("������� ����� �������� ������ > ");
    readStringFromConsole(CITY_NAME);
	
    printf("������� ����� ��� ������� > ");
    readStringFromConsole(REGION_CODE);

    printf("������� ����� ���� ��������� (��� �������������) > ");
    readStringFromConsole(FOUNDATION_DATE);

    printf("������� ����� ������ � ��������� > ");
    readStringFromConsole(CITY_POPULATION);

    if(FOUNDATION_DATE[0] == '\0') {
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update CITY set CITY_NAME = $1  , REGION_CODE = $2  , CITY_POPULATION = $3  where CITY_NAME = $4 ", 
	ECPGt_char,(CITY_NAME),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(REGION_CODE),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_POPULATION),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_NAME_key),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 66 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

if (sqlca.sqlcode == ECPG_NOT_FOUND) error3 ( );
#line 66 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 66 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 66 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

    } else {
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update CITY set CITY_NAME = $1  , REGION_CODE = $2  , FOUNDATION_DATE = $3  , CITY_POPULATION = $4  where CITY_NAME = $5 ", 
	ECPGt_char,(CITY_NAME),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(REGION_CODE),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(FOUNDATION_DATE),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_POPULATION),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_NAME_key),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 68 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

if (sqlca.sqlcode == ECPG_NOT_FOUND) error3 ( );
#line 68 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 68 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 68 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

    }
	/* exec sql whenever sqlerror  call error1 ( ) ; */
#line 70 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

	/* exec sql whenever sql_warning  call error2 ( ) ; */
#line 71 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

	/* exec sql whenever not found  call error3 ( ) ; */
#line 72 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"
	
    { ECPGtrans(__LINE__, NULL, "commit");
#line 73 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 73 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 73 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

    printf("\n");
    return 0;
}

int InsertCityTable() {
    printf("������� �������� ������ > ");
    readStringFromConsole(CITY_NAME);
	
    printf("������� ��� ������� > ");
    readStringFromConsole(REGION_CODE);

    printf("������� ���� ��������� ������ > ");
    readStringFromConsole(FOUNDATION_DATE);

    printf("������� ����������� ��������� > ");
    readStringFromConsole(CITY_POPULATION);

    if(FOUNDATION_DATE[0] == '\0') {
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into CITY ( CITY_NAME , REGION_CODE , CITY_POPULATION ) values ( $1  , $2  , $3  )", 
	ECPGt_char,(CITY_NAME),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(REGION_CODE),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_POPULATION),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 92 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

if (sqlca.sqlcode == ECPG_NOT_FOUND) error3 ( );
#line 92 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 92 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 92 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

    } else {
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into CITY ( CITY_NAME , REGION_CODE , FOUNDATION_DATE , CITY_POPULATION ) values ( $1  , $2  , $3  , $4  )", 
	ECPGt_char,(CITY_NAME),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(REGION_CODE),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(FOUNDATION_DATE),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_POPULATION),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 94 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

if (sqlca.sqlcode == ECPG_NOT_FOUND) error3 ( );
#line 94 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 94 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 94 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

    }
	/* exec sql whenever sqlerror  call error1 ( ) ; */
#line 96 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

	/* exec sql whenever sql_warning  call error2 ( ) ; */
#line 97 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

	/* exec sql whenever not found  call error3 ( ) ; */
#line 98 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 99 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 99 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 99 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

    printf("\n");
    return 0;
}

int DeleteCityTable() {
    printf("������� �������� ������, ������� �� ������ �������: > ");
    readStringFromConsole(CITY_NAME);
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from CITY where CITY_NAME = $1 ", 
	ECPGt_char,(CITY_NAME),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 107 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

if (sqlca.sqlcode == ECPG_NOT_FOUND) error3 ( );
#line 107 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 107 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 107 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

	/* exec sql whenever sqlerror  call error1 ( ) ; */
#line 108 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

	/* exec sql whenever sql_warning  call error2 ( ) ; */
#line 109 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

	/* exec sql whenever not found  call error3 ( ) ; */
#line 110 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 111 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 111 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 111 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

    printf("\n");
    return 0;
}

int SelectCityTable() {
    printf("������� ��� �������, ��� �������� ������ �������� ������ ������ > ");
    readStringFromConsole(REGION_CODE_key);

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select CITY_NAME , REGION_CODE , FOUNDATION_DATE , CITY_POPULATION from CITY where REGION_CODE = $1 ", 
	ECPGt_char,(REGION_CODE_key),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_char,(CITY_NAME),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(REGION_CODE),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(FOUNDATION_DATE),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_POPULATION),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 120 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

if (sqlca.sqlcode == ECPG_NOT_FOUND) error3 ( );
#line 120 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 120 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 120 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

    printf(" �������� ������: %s\n ��� �������: %s\n ���� ���������: %s\n ���������: %s\n", CITY_NAME, REGION_CODE, FOUNDATION_DATE, CITY_POPULATION);
	
    	/* exec sql whenever sqlerror  call error1 ( ) ; */
#line 123 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

    	/* exec sql whenever sql_warning  call error2 ( ) ; */
#line 124 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

    	/* exec sql whenever not found  call error3 ( ) ; */
#line 125 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 126 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 126 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 126 "D:\\RGR2_DB\\RGR2_DB\\CityActions.txt"

    printf("\n");
    return 0;
}
