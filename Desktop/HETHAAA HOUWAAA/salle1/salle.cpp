#include "salle.h"

/*Salle::Salle(int nombre, int numero, QString tyype, QString equipement)
{
  this->tyype=tyype;
  this->nombre=nombre;
  this->equipement=equipement;
  this->numero=numero;




}
bool Salle:: ajouter()
{
    QSqlQuery qry ;

    QString numero_string=QString::number(numero);
    QString nombre_string=QString::number(nombre);
    qry.prepare("INSERT INTO Etudiant (REF, MODELE, ETAT,DATE1,PRIX) "
                  "VALUES (:id, :forename, :surname,:forename1,:id1)");
       qry.bindValue(":nombre",nombre);
       qry.bindValue(":tyype",tyype);
       qry.bindValue(":numero",numero);
       qry.bindValue(":equipement",equipement);

       return qry.exec();
}
/*QSqlQueryModel * Salle::afficher()
{
  QSqlQueryModel *model = new QSqlQueryModel();
  model->setQuery("SELECT *FROM Salle");
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("NUMERO"));
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOMBRE"));
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("EQUIPEMENT"));
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYYPE"));



}
bool Salle::supprimer(int nombre)
{
  QSqlQuery qry ;
  QString res = QString::number(nombre);
  qry.prepare("Delete from Salle where NOMBRE=:NOMBRE");
  qry.bindValue(":NOMBRE",res);
  return qry.exec();

}
bool Salle::modifier()
{
  QSqlQuery query;

  query.prepare("UPDATE Salle set  tyype=:tyype,equipement=:equipement where numero=:numero");

   query.bindValue(":numero", numero);
   query.bindValue(":tyype",tyype);
   query.bindValue(":equipement", equipement);
   query.bindValue(":nombre", nombre);

 return query.exec();}

*/
salle::salle()
{

}
bool salle::ajouter()
{
    QSqlQuery query;
    //QString numero_string=QString::number(numero);
    //QString nombre_string=QString::number(nombre);
    query.prepare("INSERT INTO salle (numero,nombre,tyype,equipement,video) "
      "VALUES (:numero, :nombre, :tyype, :equipement, :video)");
    query.bindValue(":numero",numero);
    query.bindValue(":nombre", nombre);
    query.bindValue(":tyype", tyype);
    query.bindValue(":equipement",equipement );
    query.bindValue(":video",video );

return query.exec();


}
QSqlQueryModel *salle ::afficher()
{
QSqlQueryModel*model =new QSqlQueryModel();

     model->setQuery("SELECT* FROM salle ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero"));
     model->setHeaderData(1, Qt::Horizontal,QObject::tr("nombre"));
     model->setHeaderData(2, Qt::Horizontal,QObject::tr("tyype"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("equipement"));


          /*QTableView *view = new QTableView;
            view->setModel(model);
            view->show();*/

return model;
}
bool salle::supprimer()
{
    QSqlQuery query;
QString numero_string=QString::number(numero);
    query.prepare("DELETE FROM salle where  numero=:numero");

    query.bindValue(":numero",numero_string);

return query.exec();




}
bool salle::modifier()
{
    QSqlQuery query;
    query.prepare("update salle set numero=:numero, nombre=:nombre, tyype=:tyype,equipement=:equipement where numero=:numero");
    query.bindValue(":numero",numero );
    query.bindValue(":nombre", nombre);
    query.bindValue(":tyype", tyype);
    query.bindValue(":equipement",equipement );
    return query.exec();

}

QSqlQueryModel *salle::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from SALLE where NUMERO LIKE '"+rech+"%'");
    return model;
}

QSqlQueryModel *salle::tri(){

   QSqlQuery *q = new QSqlQuery();
   QSqlQueryModel *model = new QSqlQueryModel();
   q->prepare("SELECT * FROM SALLE ORDER BY NOMBRE ");
   q->exec();
   model->setQuery(*q);

   return model;
}
/*
QSqlQueryModel *Reparations::trid(){

   QSqlQuery *q = new QSqlQuery();
   QSqlQueryModel *model = new QSqlQueryModel();
   q->prepare("SELECT * FROM SALLE ORDER BY NOMBRE DESC");
   q->exec();
   model->setQuery(*q);

   return model;
}
*/
QString salle::rechercherV(int rech)
{
    QSqlQuery *salle = new QSqlQuery();

        salle->prepare("select video from SALLE where NUMERO =:rech");
        salle->bindValue(":rech",rech);
        salle->exec();
        salle->next();
        return salle->value(0).toString();
}
