package DatabaseApp;


/**
* DatabaseApp/DatabaseImplPOA.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from Database.idl
* Friday, March 5, 2021 12:46:32 PM IST
*/

public abstract class DatabaseImplPOA extends org.omg.PortableServer.Servant
 implements DatabaseApp.DatabaseImplOperations, org.omg.CORBA.portable.InvokeHandler
{

  // Constructors

  private static java.util.Hashtable _methods = new java.util.Hashtable ();
  static
  {
    _methods.put ("getStudentData", new java.lang.Integer (0));
  }

  public org.omg.CORBA.portable.OutputStream _invoke (String $method,
                                org.omg.CORBA.portable.InputStream in,
                                org.omg.CORBA.portable.ResponseHandler $rh)
  {
    org.omg.CORBA.portable.OutputStream out = null;
    java.lang.Integer __method = (java.lang.Integer)_methods.get ($method);
    if (__method == null)
      throw new org.omg.CORBA.BAD_OPERATION (0, org.omg.CORBA.CompletionStatus.COMPLETED_MAYBE);

    switch (__method.intValue ())
    {
       case 0:  // DatabaseApp/DatabaseImpl/getStudentData
       {
         DatabaseApp.Record $result[] = null;
         $result = this.getStudentData ();
         out = $rh.createReply();
         DatabaseApp.recordSeqHelper.write (out, $result);
         break;
       }

       default:
         throw new org.omg.CORBA.BAD_OPERATION (0, org.omg.CORBA.CompletionStatus.COMPLETED_MAYBE);
    }

    return out;
  } // _invoke

  // Type-specific CORBA::Object operations
  private static String[] __ids = {
    "IDL:DatabaseApp/DatabaseImpl:1.0"};

  public String[] _all_interfaces (org.omg.PortableServer.POA poa, byte[] objectId)
  {
    return (String[])__ids.clone ();
  }

  public DatabaseImpl _this() 
  {
    return DatabaseImplHelper.narrow(
    super._this_object());
  }

  public DatabaseImpl _this(org.omg.CORBA.ORB orb) 
  {
    return DatabaseImplHelper.narrow(
    super._this_object(orb));
  }


} // class DatabaseImplPOA
