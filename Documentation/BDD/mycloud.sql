-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

-- -----------------------------------------------------
-- Schema mycloud
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema mycloud
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `mycloud` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci ;
USE `mycloud` ;

-- -----------------------------------------------------
-- Table `mycloud`.`User`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mycloud`.`user` (
  `idUser` INT NOT NULL AUTO_INCREMENT,
  `nom` VARCHAR(250) NULL,
  `prenom` VARCHAR(250) NULL,
  `ip` VARCHAR(45) NULL,
  `adresseMail` VARCHAR(250) NULL,
  `dateSyn` DATE NULL,
  `tokenConf` VARCHAR(45) NULL,
  PRIMARY KEY (`idUser`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mycloud`.`Files`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mycloud`.`Files` (
  `idFiles` INT NOT NULL,
  `nameFile` VARCHAR(250) NULL,
  `path` VARCHAR(250) NULL,
  `dateUpload` VARCHAR(250) NULL,
  `poids` FLOAT NULL,
  `type` VARCHAR(45) NULL,
  `User_idUser` INT NOT NULL,
  PRIMARY KEY (`idFiles`, `User_idUser`),
  INDEX `fk_Files_User_idx` (`User_idUser` ASC),
  CONSTRAINT `fk_Files_User`
    FOREIGN KEY (`User_idUser`)
    REFERENCES `mycloud`.`User` (`idUser`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mycloud`.`logs`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mycloud`.`logs` (
  `idlogs` INT NOT NULL AUTO_INCREMENT,
  `logs` LONGTEXT NULL,
  `User_idUser` INT NOT NULL,
  PRIMARY KEY (`idlogs`, `User_idUser`),
  INDEX `fk_logs_User1_idx` (`User_idUser` ASC),
  CONSTRAINT `fk_logs_User1`
    FOREIGN KEY (`User_idUser`)
    REFERENCES `mycloud`.`User` (`idUser`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
