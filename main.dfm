object Okno: TOkno
  Left = 277
  Top = 187
  Width = 1044
  Height = 540
  Caption = 'Okno'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  WindowState = wsMaximized
  PixelsPerInch = 96
  TextHeight = 13
  object ObszarObrazu: TPaintBox
    Left = 193
    Top = 0
    Width = 835
    Height = 501
    Align = alClient
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 193
    Height = 501
    Align = alLeft
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 200
      Width = 42
      Height = 13
      Caption = 'Ruszaj X'
    end
    object Label2: TLabel
      Left = 16
      Top = 280
      Width = 42
      Height = 13
      Caption = 'Ruszaj Y'
    end
    object Label3: TLabel
      Left = 16
      Top = 8
      Width = 83
      Height = 13
      Caption = 'Osrodek pierwszy'
    end
    object Label4: TLabel
      Left = 16
      Top = 64
      Width = 66
      Height = 13
      Caption = 'Osrodek drugi'
    end
    object Label5: TLabel
      Left = 16
      Top = 112
      Width = 56
      Height = 13
      Caption = 'k'#261't padania'
    end
    object Label6: TLabel
      Left = 16
      Top = 152
      Width = 67
      Height = 13
      Caption = 'k'#261't za'#322'amania'
    end
    object CBOsrodkiN1: TComboBox
      Left = 16
      Top = 32
      Width = 145
      Height = 21
      ItemHeight = 13
      ItemIndex = 0
      TabOrder = 0
      Text = 'powietrze'
      OnChange = CBOsrodkiN1Change
      Items.Strings = (
        'powietrze'
        'woda'
        'typowe szk'#322'o'
        'diament')
    end
    object CBOsrodkiN2: TComboBox
      Left = 16
      Top = 80
      Width = 145
      Height = 21
      ItemHeight = 13
      ItemIndex = 1
      TabOrder = 1
      Text = 'woda'
      OnChange = CBOsrodkiN2Change
      Items.Strings = (
        'powietrze'
        'woda'
        'typowe szk'#322'o'
        'diament')
    end
    object TBZmianaPozycjiX: TTrackBar
      Left = 8
      Top = 232
      Width = 150
      Height = 45
      Orientation = trHorizontal
      Frequency = 1
      Position = 0
      SelEnd = 0
      SelStart = 0
      TabOrder = 2
      TickMarks = tmBottomRight
      TickStyle = tsAuto
      OnChange = TBZmianaPozycjiXChange
    end
    object TBZmianaPozycjiY: TTrackBar
      Left = 8
      Top = 304
      Width = 150
      Height = 45
      Orientation = trHorizontal
      Frequency = 1
      Position = 1
      SelEnd = 0
      SelStart = 0
      TabOrder = 3
      TickMarks = tmBottomRight
      TickStyle = tsAuto
      OnChange = TBZmianaPozycjiYChange
    end
    object EDKatPadania: TEdit
      Left = 16
      Top = 128
      Width = 121
      Height = 21
      Enabled = False
      TabOrder = 4
    end
    object EDKatZalamania: TEdit
      Left = 16
      Top = 176
      Width = 121
      Height = 21
      Enabled = False
      TabOrder = 5
    end
  end
  object TimerStart: TTimer
    Enabled = False
    Interval = 100
    OnTimer = TimerStartTimer
    Left = 216
    Top = 16
  end
end
