package DatabaseApp;


/**
* DatabaseApp/DatabaseImplHelper.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from Database.idl
* Friday, March 5, 2021 12:46:32 PM IST
*/

abstract public class DatabaseImplHelper
{
  private static String  _id = "IDL:DatabaseApp/DatabaseImpl:1.0";

  public static void insert (org.omg.CORBA.Any a, DatabaseApp.DatabaseImpl that)
  {
    org.omg.CORBA.portable.OutputStream out = a.create_output_stream ();
    a.type (type ());
    write (out, that);
    a.read_value (out.create_input_stream (), type ());
  }

  public static DatabaseApp.DatabaseImpl extract (org.omg.CORBA.Any a)
  {
    return read (a.create_input_stream ());
  }

  private static org.omg.CORBA.TypeCode __typeCode = null;
  synchronized public static org.omg.CORBA.TypeCode type ()
  {
    if (__typeCode == null)
    {
      __typeCode = org.omg.CORBA.ORB.init ().create_interface_tc (DatabaseApp.DatabaseImplHelper.id (), "DatabaseImpl");
    }
    return __typeCode;
  }

  public static String id ()
  {
    return _id;
  }

  public static DatabaseApp.DatabaseImpl read (org.omg.CORBA.portable.InputStream istream)
  {
    return narrow (istream.read_Object (_DatabaseImplStub.class));
  }

  public static void write (org.omg.CORBA.portable.OutputStream ostream, DatabaseApp.DatabaseImpl value)
  {
    ostream.write_Object ((org.omg.CORBA.Object) value);
  }

  public static DatabaseApp.DatabaseImpl narrow (org.omg.CORBA.Object obj)
  {
    if (obj == null)
      return null;
    else if (obj instanceof DatabaseApp.DatabaseImpl)
      return (DatabaseApp.DatabaseImpl)obj;
    else if (!obj._is_a (id ()))
      throw new org.omg.CORBA.BAD_PARAM ();
    else
    {
      org.omg.CORBA.portable.Delegate delegate = ((org.omg.CORBA.portable.ObjectImpl)obj)._get_delegate ();
      DatabaseApp._DatabaseImplStub stub = new DatabaseApp._DatabaseImplStub ();
      stub._set_delegate(delegate);
      return stub;
    }
  }

  public static DatabaseApp.DatabaseImpl unchecked_narrow (org.omg.CORBA.Object obj)
  {
    if (obj == null)
      return null;
    else if (obj instanceof DatabaseApp.DatabaseImpl)
      return (DatabaseApp.DatabaseImpl)obj;
    else
    {
      org.omg.CORBA.portable.Delegate delegate = ((org.omg.CORBA.portable.ObjectImpl)obj)._get_delegate ();
      DatabaseApp._DatabaseImplStub stub = new DatabaseApp._DatabaseImplStub ();
      stub._set_delegate(delegate);
      return stub;
    }
  }

}
