-- MySQL dump 10.13  Distrib 5.7.21, for Linux (x86_64)
--
-- Host: localhost    Database: hangman
-- ------------------------------------------------------
-- Server version	5.7.21

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `animals`
--

DROP TABLE IF EXISTS `animals`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `animals` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `secret_word` varchar(80) NOT NULL,
  `tip` tinytext NOT NULL,
  `chances` tinyint(4) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `animals`
--

LOCK TABLES `animals` WRITE;
/*!40000 ALTER TABLE `animals` DISABLE KEYS */;
INSERT INTO `animals` VALUES (1,'macaco','Costuma viver na selva e gosta de banana.',2);
/*!40000 ALTER TABLE `animals` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `fruits`
--

DROP TABLE IF EXISTS `fruits`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `fruits` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `secret_word` varchar(80) NOT NULL,
  `tip` tinytext NOT NULL,
  `chances` tinyint(4) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `fruits`
--

LOCK TABLES `fruits` WRITE;
/*!40000 ALTER TABLE `fruits` DISABLE KEYS */;
INSERT INTO `fruits` VALUES (1,'abacaxi','Símbolo das regiões tropicais',3),(2,'goiaba','Costuma ser verde por fora e rosa por dentro',4),(3,'abacate','Normalmente é verde tanto por fora quanto por dentro e tem um grande caroço/semente em seu interior',4),(4,'graviola','Lembra um pouco a jaca e começa com a letra g',4),(5,'pinha','Trata-se de uma fruta popularmente chamada de fruta-do-conde',5),(6,'tomate','É um fruto avermelhado que nós costumamos colocar na salada',2),(7,'uva','Fruta chave para se fazer vinho',2),(8,'morango','Trata-se de uma fruta que cientificamente NÃO é considerada uma fruta e sua cor é normalmente avermelhada',6),(9,'umbu','Origina-se de uma ávore popularmente conhecida como umbuzeiro',1),(10,'laranja','FRUTA USADA NO SUCO DO JAISON MENDES',1);
/*!40000 ALTER TABLE `fruits` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `objects`
--

DROP TABLE IF EXISTS `objects`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `objects` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `secret_word` varchar(80) NOT NULL,
  `tip` tinytext NOT NULL,
  `chances` tinyint(4) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `objects`
--

LOCK TABLES `objects` WRITE;
/*!40000 ALTER TABLE `objects` DISABLE KEYS */;
INSERT INTO `objects` VALUES (1,'vaso sanitario','É onde nois defeca',4),(2,'gardem gnome','Objetos presente no jogo Half-Life: Episode Two que garante a conquista Little Rocket Man',5),(3,'c4','Explosivo plastica bastante usado pelas forças dos EUA',4),(4,'rodo','Lembra a vassoura, porém este serve para tirar a água e não a poeira',2),(5,'onibus','Veiculo de transporte público com PNEUS!!!',4),(6,'balde','Recipiente grande para colocar água',2),(7,'isqueiro','Trata-se de um dispositivo portátil usado para criar chamas',3),(8,'isopor','É conhecido também pelo nome poliestireno e varia de sólido para o espumado',4),(9,'lampada incandescente','Dispositivo electrico que transforma energia elétrica em energia luminosa e energia térmica',4),(10,'mola','Trata-se de um objeto elastico com formato helicoidal que armazena energia mecância',2),(11,'brinquedo','Objeto usado por crianças para bricar e se divertir',2);
/*!40000 ALTER TABLE `objects` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `players_score`
--

DROP TABLE IF EXISTS `players_score`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `players_score` (
  `playerID` int(11) NOT NULL AUTO_INCREMENT,
  `nickname` varchar(21) NOT NULL,
  `total_points` int(11) NOT NULL,
  `total_errors` int(11) NOT NULL,
  `total_wins` int(11) NOT NULL,
  `total_losses` int(11) NOT NULL,
  `total_matches` int(11) NOT NULL,
  PRIMARY KEY (`playerID`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `players_score`
--

LOCK TABLES `players_score` WRITE;
/*!40000 ALTER TABLE `players_score` DISABLE KEYS */;
INSERT INTO `players_score` VALUES (1,'Test',20,0,2,0,2),(2,'Test_2',24,4,1,0,1);
/*!40000 ALTER TABLE `players_score` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-04-19 22:26:51
