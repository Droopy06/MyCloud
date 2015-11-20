-- phpMyAdmin SQL Dump
-- version 4.5.1
-- http://www.phpmyadmin.net
--
-- Client :  localhost
-- Généré le :  Ven 20 Novembre 2015 à 13:21
-- Version du serveur :  5.5.46-0+deb7u1
-- Version de PHP :  5.6.15-1~dotdeb+7.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `mycloud`
--

-- --------------------------------------------------------

--
-- Structure de la table `Files`
--

CREATE TABLE `Files` (
  `idFiles` int(11) NOT NULL,
  `nameFile` varchar(250) DEFAULT NULL,
  `path` varchar(250) DEFAULT NULL,
  `dateUpload` datetime DEFAULT NULL,
  `poids` float DEFAULT NULL,
  `type` varchar(45) DEFAULT NULL,
  `User_idUser` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `logs`
--

CREATE TABLE `logs` (
  `idlogs` int(11) NOT NULL,
  `logs` longtext,
  `User_idUser` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `User`
--

CREATE TABLE `User` (
  `idUser` int(11) NOT NULL,
  `nom` varchar(250) DEFAULT NULL,
  `prenom` varchar(250) DEFAULT NULL,
  `pseudo` varchar(250) NOT NULL,
  `mdp` varchar(250) NOT NULL,
  `ip` varchar(45) DEFAULT NULL,
  `adresseMail` varchar(250) DEFAULT NULL,
  `dateSyn` datetime DEFAULT NULL,
  `tokenConf` varchar(45) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Index pour les tables exportées
--

--
-- Index pour la table `Files`
--
ALTER TABLE `Files`
  ADD PRIMARY KEY (`idFiles`,`User_idUser`),
  ADD KEY `fk_Files_User_idx` (`User_idUser`);

--
-- Index pour la table `logs`
--
ALTER TABLE `logs`
  ADD PRIMARY KEY (`idlogs`,`User_idUser`),
  ADD KEY `fk_logs_User1_idx` (`User_idUser`);

--
-- Index pour la table `User`
--
ALTER TABLE `User`
  ADD PRIMARY KEY (`idUser`);

--
-- Contraintes pour les tables exportées
--

--
-- Contraintes pour la table `Files`
--
ALTER TABLE `Files`
  ADD CONSTRAINT `fk_Files_User` FOREIGN KEY (`User_idUser`) REFERENCES `User` (`idUser`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Contraintes pour la table `logs`
--
ALTER TABLE `logs`
  ADD CONSTRAINT `fk_logs_User1` FOREIGN KEY (`User_idUser`) REFERENCES `User` (`idUser`) ON DELETE NO ACTION ON UPDATE NO ACTION;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
