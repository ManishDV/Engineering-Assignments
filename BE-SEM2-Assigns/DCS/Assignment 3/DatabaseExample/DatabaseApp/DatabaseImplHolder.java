package DatabaseApp;

/**
* DatabaseApp/DatabaseImplHolder.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from Database.idl
* Friday, March 5, 2021 12:46:32 PM IST
*/

public final class DatabaseImplHolder implements org.omg.CORBA.portable.Streamable
{
  public DatabaseApp.DatabaseImpl value = null;

  public DatabaseImplHolder ()
  {
  }

  public DatabaseImplHolder (DatabaseApp.DatabaseImpl initialValue)
  {
    value = initialValue;
  }

  public void _read (org.omg.CORBA.portable.InputStream i)
  {
    value = DatabaseApp.DatabaseImplHelper.read (i);
  }

  public void _write (org.omg.CORBA.portable.OutputStream o)
  {
    DatabaseApp.DatabaseImplHelper.write (o, value);
  }

  public org.omg.CORBA.TypeCode _type ()
  {
    return DatabaseApp.DatabaseImplHelper.type ();
  }

}
