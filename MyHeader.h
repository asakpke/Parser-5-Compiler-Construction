// MakeTokenGUIDlg.h : header file
//

#if !defined(MY_HEADER_FILE)
#define MY_HEADER_FILE

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

const char cEndOfLine	= 10; // or = '\n'
const char cEndOfFile	= EOF;
const nTotalReserveWords = 66; // 0 to 65

//total resv words = 66
enum ETokenType { rvAsm,rvAuto,rvBadCast,rvBadTypeID,rvBool,rvBreak
	,rvCase,rvCatch,rvChar,rvClass,rvConst,rvConstCast,rvContinue
	,rvDefault,rvDelete,rvDo,rvDouble,rvDynamicCast,rvElse,rvEnum
	,rvExcept,rvExplicit,rvExtern,rvFalse,rvFinally,rvFloat,rvFor
	,rvFriend,rvGoto,rvIf,rvInline,rvInt,rvLong,rvMutable,rvNamespace
	,rvNew,rvOperator,rvPrivate,rvProtected,rvPublic,rvRetister
	,rvReinterpret_cast,rvReturn,rvShort,rvSigned,rvSizeof,rvStatic
	,rvStaticCast,rvStruct,rvSwitch,rvTemplate,rvThis,rvthrow,rvTrue
	,rvTry,rvTypeInfo,rvTypedef,rvTypeID,rvTypeName,rvUnion,rvUnsigned
	,rvUsing,rvVirtual,rvVoid,rvVolatile,rvWhile

	,ttNull=66,ttNumber,ttDecimal,ttChar,ttString,ttNames,ttResvWord
	,ttCComments,ttCPPComments,ttPreProcessor,ttFunction
	,ttStatementEnd,ttFunctionStartBracket,ttFunctionEndBracket
	,ttFullStop,ttComma,ttVBComments

	// operators
	,opAssignment,opPlusMinus,opMultiplyDivide
	// conditional operators
	,condOpEqual,condOpLessThanEqual,condOpNotEqual,condOpLessThan
	,condOpGreaterThanEqual,condOpGreaterThan
};
//enum bool2 { false2,true2,none };

#endif // !defined(MY_HEADER_FILE)