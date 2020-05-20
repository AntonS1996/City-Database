CREATE TABLE CITY (
    CITY_NAME 	     VARCHAR,   /* Название города */
    REGION_CODE      VARCHAR,   /* Код региона */
    FOUNDATION_DATE  VARCHAR,   /* Дата основания */
    CITY_POPULATION  VARCHAR,   /* Население */
    CONSTRAINT "city_key" PRIMARY KEY (CITY_NAME)
);

CREATE TABLE DISTRICT (
    DISTRICT_NAME  	     VARCHAR,   /* Название района */
    OKRUG    		     VARCHAR,   /* Округ */
    AREA      		     VARCHAR,   /* Площадь */
    DISTRCIT_POPULATION  VARCHAR,   /* Население */
    CITY_NAME     	     VARCHAR,   /* Название города */
    CONSTRAINT "district_key" PRIMARY KEY (DISTRICT_NAME, CITY_NAME),
    
    FOREIGN KEY (CITY_NAME) REFERENCES CITY(CITY_NAME) /* Связь между городом и районом */
    ON UPDATE CASCADE
    ON DELETE CASCADE
);

CREATE TABLE STREET (
    STREET_NAME     VARCHAR,   /* Название улицы */
    TRAFFIC    	    VARCHAR,   /* Движение */
    CITY_NAME       VARCHAR,   /* Название города */
    DISTRICT_NAME   VARCHAR,   /* Название района */
    CONSTRAINT "street_key" PRIMARY KEY (STREET_NAME, CITY_NAME, DISTRICT_NAME),
    
    FOREIGN KEY (CITY_NAME, DISTRICT_NAME) REFERENCES DISTRICT(CITY_NAME, DISTRICT_NAME) /* Связь между районом и улицей */
    ON UPDATE CASCADE
    ON DELETE CASCADE
);

CREATE TABLE BUILDING (
    NUM  	        VARCHAR,    /* Номер */
    POSTCODE        VARCHAR,    /* Почтовый индекс */
    BUILDING_TYPE   VARCHAR,    /* Тип здания */
    CITY_NAME       VARCHAR,    /* Название города */
    DISTRICT_NAME   VARCHAR,    /* Название района */
    STREET_NAME     VARCHAR,    /* Название улицы */
    CONSTRAINT "building_key" PRIMARY KEY (NUM, POSTCODE, CITY_NAME, DISTRICT_NAME, STREET_NAME),
    
    FOREIGN KEY (CITY_NAME, DISTRICT_NAME, STREET_NAME) REFERENCES STREET(CITY_NAME, DISTRICT_NAME, STREET_NAME) /* Связь между улицей и зданием */
    ON UPDATE CASCADE
    ON DELETE CASCADE
);

CREATE TABLE LANDMARK (
    LANDMARK_NAME   VARCHAR,   /* Название достопримечательности */
    CREATION_YEAR   VARCHAR,   /* Год создания */
    LANDMARK_TYPE   VARCHAR,   /* Тип */
    ARCHITECT 	    VARCHAR,   /* Архитектор */
    CITY_NAME       VARCHAR,   /* Название города */
    CONSTRAINT "landmark_key" PRIMARY KEY (LANDMARK_NAME)
);



INSERT INTO CITY(CITY_NAME, REGION_CODE, FOUNDATION_DATE, CITY_POPULATION) VALUES('Москва', '77', '1147', '12380664');

INSERT INTO DISTRICT(DISTRICT_NAME, OKRUG, AREA, DISTRCIT_POPULATION, CITY_NAME) VALUES('Измайлово', 'Восточный', '15.24', '106154', 'Москва');
INSERT INTO DISTRICT(DISTRICT_NAME, OKRUG, AREA, DISTRCIT_POPULATION, CITY_NAME) VALUES('Якиманка', 'Центральный', '4.80', '27463', 'Москва');
INSERT INTO DISTRICT(DISTRICT_NAME, OKRUG, AREA, DISTRCIT_POPULATION, CITY_NAME) VALUES('Замоскворечье', 'Центральный', '4.32', '57871', 'Москва');
INSERT INTO DISTRICT(DISTRICT_NAME, OKRUG, AREA, DISTRCIT_POPULATION, CITY_NAME) VALUES('Пресненский', 'Центральный', '11.70', '126178', 'Москва');
INSERT INTO DISTRICT(DISTRICT_NAME, OKRUG, AREA, DISTRCIT_POPULATION, CITY_NAME) VALUES('Северное Измайлово', 'Восточный', '4.20', '87247', 'Москва');

INSERT INTO STREET(STREET_NAME, TRAFFIC, CITY_NAME, DISTRICT_NAME) VALUES('Первомайская ул.', 'Двустороннее', 'Москва', 'Измайлово');
INSERT INTO STREET(STREET_NAME, TRAFFIC, CITY_NAME, DISTRICT_NAME) VALUES('Измайловский бульвар', 'Двустороннее', 'Москва', 'Измайлово');
INSERT INTO STREET(STREET_NAME, TRAFFIC, CITY_NAME, DISTRICT_NAME) VALUES('Щёлковское шоссе', 'Двустороннее', 'Москва', 'Северное Измайлово');
INSERT INTO STREET(STREET_NAME, TRAFFIC, CITY_NAME, DISTRICT_NAME) VALUES('Пресненская набережная', 'Двустороннее', 'Москва', 'Пресненский');
INSERT INTO STREET(STREET_NAME, TRAFFIC, CITY_NAME, DISTRICT_NAME) VALUES('Мытная ул.', 'Двустороннее', 'Москва', 'Якиманка');

INSERT INTO BUILDING(NUM, POSTCODE, BUILDING_TYPE, CITY_NAME, DISTRICT_NAME, STREET_NAME) VALUES('39', '105043', 'Жилое', 'Москва', 'Измайлово', 'Первомайская');
INSERT INTO BUILDING(NUM, POSTCODE, BUILDING_TYPE, CITY_NAME, DISTRICT_NAME, STREET_NAME) VALUES('11/31', '105264', 'Жилое', 'Москва', 'Измайлово', 'Измайловский бульвар');
INSERT INTO BUILDING(NUM, POSTCODE, BUILDING_TYPE, CITY_NAME, DISTRICT_NAME, STREET_NAME) VALUES('12', '123100', 'Офисное', 'Москва', 'Пресненский', 'Пресненская набережная');
INSERT INTO BUILDING(NUM, POSTCODE, BUILDING_TYPE, CITY_NAME, DISTRICT_NAME, STREET_NAME) VALUES('40', '115162', 'Офисное', 'Москва', 'Якиманка', 'Мытная ул.');

INSERT INTO LANDMARK(LANDMARK_NAME, CREATION_YEAR, LANDMARK_TYPE, ARCHITECT, CITY_NAME) VALUES('Храм Христа Спасителя', '1812', 'Собор', 'К. А. Тон', 'Москва');
INSERT INTO LANDMARK(LANDMARK_NAME, CREATION_YEAR, LANDMARK_TYPE, ARCHITECT, CITY_NAME) VALUES('Московский Кремль', '1482—1495', 'Крепость', '-', 'Москва');
INSERT INTO LANDMARK(LANDMARK_NAME, CREATION_YEAR, LANDMARK_TYPE, ARCHITECT, CITY_NAME) VALUES('Останкинская телебашня', '1960—1967', 'Телебашня', 'Л. И. Баталов', 'Москва');
INSERT INTO LANDMARK(LANDMARK_NAME, CREATION_YEAR, LANDMARK_TYPE, ARCHITECT, CITY_NAME) VALUES('Москва-Сити', '1995—2020', 'Деловой центр', 'Б. И. Тхор', 'Москва');
