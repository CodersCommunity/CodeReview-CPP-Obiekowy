object Form1: TForm1
  Left = 563
  Top = 249
  Width = 520
  Height = 192
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  Caption = 'Odliczanie czasu'
  Color = clBtnFace
  UseDockManager = True
  DockSite = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 0
    Top = 40
    Width = 497
    Height = 65
    Alignment = taCenter
    AutoSize = False
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -64
    Font.Name = 'Geometr706 BlkCn BT'
    Font.Style = []
    ParentFont = False
    Transparent = True
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 8
    Top = 16
  end
end
