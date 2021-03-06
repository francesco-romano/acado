
#ifndef ACADO_TOOLKIT_EXPORT_DATA_INTERNAL_HPP
#define ACADO_TOOLKIT_EXPORT_DATA_INTERNAL_HPP

#include <casadi/symbolic/shared_object.hpp>
#include <acado/utils/acado_utils.hpp>

BEGIN_NAMESPACE_ACADO

class ExportDataInternal : public CasADi::SharedObjectNode
{
public:

	/** Default constructor which optionally takes name and type string
	 *	of the data object.
	 *
	 *	@param[in] _name			Name of the data object.
	 *	@param[in] _type			Data type of the data object.
	 *	@param[in] _dataStruct		Global data struct to which the data object belongs to (if any).
	 *	@param[in] _prefix			Optional prefix that will be put in front of the name.
	 */
	explicit ExportDataInternal(	const String& _name = emptyConstString,
									ExportType _type = REAL,
									ExportStruct _dataStruct = ACADO_LOCAL,
									const String& _prefix = emptyConstString
									);

	/** Destructor.
	 */
	virtual ~ExportDataInternal( );

	virtual ExportDataInternal* clone() const = 0;

	/** Sets the name of the data object.
	 *
	 *	@param[in] _name			New name of the data object.
	 *
	 *	\return SUCCESSFUL_RETURN
	 */
	returnValue	setName(	const String& _name
							);

	/** Sets the data type of the data object.
	 *
	 *	@param[in] _type			New data type of the data object.
	 *
	 *	\return SUCCESSFUL_RETURN
	 */
	returnValue	setType(	ExportType _type
							);

	/** Sets the global data struct to which the data object belongs to.
	 *
	 *	@param[in] _dataStruct		New global data struct to which the data object belongs to.
	 *
	 *	\return SUCCESSFUL_RETURN
	 */
	returnValue	setDataStruct(	ExportStruct _dataStruct
								);

	/** Sets the prefix which is placed before the structure name.
	 *
	 *  @param[in] _prefix Prefix name.
	 *
	 *  \return SUCCESSFUL_RETURN
	 */
	returnValue setPrefix(	const String& _prefix
							);
	/** Returns the name of the data object.
	 *
	 *	\return Name of the data object
	 */
	String getName( ) const;

	/** Returns the data type of the data object.
	 *
	 *	\return Data type of the data object
	 */
	ExportType getType( ) const;

	/** Returns a string containing the data type of the data object.
	 *
	 *	@param[in] _realString		String to be used to declare real variables.
	 *	@param[in] _intString		String to be used to declare integer variables.
	 *
	 *	\return String containing the data type of the data object.
	 */
	String getTypeString(	const String& _realString = "real_t",
							const String& _intString = "int"
							) const;

	/** Returns the global data struct to which the data object belongs to.
	 *
	 *	\return Global data struct to which the data object belongs to
	 */
	ExportStruct getDataStruct( ) const;

	/** Returns a string containing the global data struct to which the data object belongs to.
	 *
	 *	\return String containing the global data struct to which the data object belongs to.
	 */
	String getDataStructString( ) const;

	/** Returns a string which contains a prefix name.
	 *
	 *  \return Prefix name
	 */
	String getPrefix( ) const;

	/** Returns the full name of the data object including the possible prefix
	 *	of the global data struct.
	 *
	 *	\return Full name of the data object
	 */
	String getFullName( ) const;


	/** Exports declaration of the index variable. Its appearance can
	 *  can be adjusted by various options.
	 *
	 *	@param[in] file				Name of file to be used to export function.
	 *	@param[in] _realString		String to be used to declare real variables.
	 *	@param[in] _intString		String to be used to declare integer variables.
	 *	@param[in] _precision		Number of digits to be used for exporting real values.
	 *
	 *	\return SUCCESSFUL_RETURN
	 */
	virtual returnValue exportDataDeclaration(	FILE* file,
												const String& _realString = "real_t",
												const String& _intString = "int",
												int _precision = 16
												) const = 0;

	/** Returns whether the index is set to a given value.
	 *
	 *	\return BT_TRUE  iff index is set to a given value, \n
	 *	        BT_FALSE otherwise
	 */
	virtual BooleanType isGiven( ) const = 0;

	virtual returnValue setDoc( const String& _doc );
	virtual String getDoc( ) const;

	//
	// PROTECTED MEMBER FUNCTIONS:
	//
protected:

	returnValue setFullName( void );

protected:

	/** Name of the data object. */
	String name;

	/** Data type of the data object. */
	ExportType type;

	/** Prefix, which is added before the structure name*/
	String prefix;

	/** Global data struct to which the data object belongs to (if any). */
	ExportStruct dataStruct;

	/** Full name of the data object including the possible prefix of the global data struct. */
	String fullName;

	/** Description of the variable */
	String description;
};

CLOSE_NAMESPACE_ACADO

#endif // ACADO_TOOLKIT_EXPORT_DATA_INTERNAL_HPP
