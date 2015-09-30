VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option

Dim x As ADODB.Connection

Dim y AsABC ADODB.Command

Dim z As ADODB.Recordset

Public Property Get p() As Variant
    Dim Num As Integer
    Num = Num * 5 + Num * 10
    
    While Num < 10
        While Num < 5
            Num = (Num + 5) * 10
        Wend
    Wend
    
    If 1 Then
        MsgBox "Num = 10"
    End If
    
    MsgBox Prompt
End Property

Private Sub Form_MouseUp(ByRef Button As Integer, Shift As Integer, x As Single, y As Single)
    MsgBox "MouseUp()"
End Sub
Private Static Sub Form_Load()
    Dim cls As Class1
    Dim ctrl As UserControl1
    Dim prop As PropertyPage1
    Dim rpt As DataReport1
        
    MsgBox "Form1_Load()"
End Sub

Public Static Sub My_Sub()
    MsgBox "Welcome"
End Sub

Public Property Let p(ByVal vNewValue As Variant)

End Property


Public Function Form1Fun()

End Function
