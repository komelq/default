object Form1: TForm1
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = 'Symulator zdarze'#324' dyskretnych '
  ClientHeight = 543
  ClientWidth = 964
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  OnKeyPress = FormKeyPress
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 289
    Height = 513
    Caption = 'Parametry symulacji'
    TabOrder = 0
    object Label1: TLabel
      Left = 3
      Top = 27
      Width = 61
      Height = 13
      Caption = 'Rozmiar sieci'
    end
    object Label2: TLabel
      Left = 3
      Top = 56
      Width = 57
      Height = 13
      Caption = 'Ilo'#347#263' iteracji'
    end
    object Label4: TLabel
      Left = 3
      Top = 81
      Width = 126
      Height = 13
      Caption = 'Liczba kana'#322#243'w w kom'#243'rce'
    end
    object Label5: TLabel
      Left = 3
      Top = 105
      Width = 86
      Height = 13
      Caption = 'Liczba abonent'#243'w'
    end
    object Label6: TLabel
      Left = 0
      Top = 132
      Width = 142
      Height = 13
      Caption = ' Prawd. rozpocz'#281'cia rozmowy'
    end
    object Label8: TLabel
      Left = 3
      Top = 162
      Width = 104
      Height = 13
      Caption = 'Szeroko'#347#263' autostrady'
    end
    object Label9: TLabel
      Left = 129
      Top = 231
      Width = 28
      Height = 13
      Caption = '70/30'
    end
    object Label14: TLabel
      Left = 217
      Top = 231
      Width = 48
      Height = 13
      Caption = 'Statyczny'
    end
    object Label15: TLabel
      Left = 18
      Top = 231
      Width = 54
      Height = 13
      Caption = 'Autostrada'
    end
    object RozmiarSieciCB: TComboBox
      Left = 152
      Top = 21
      Width = 97
      Height = 21
      ItemHeight = 13
      ItemIndex = 8
      TabOrder = 0
      Text = '10 x 10'
      OnKeyPress = RozmiarSieciCBKeyPress
      Items.Strings = (
        '2 x 2'
        '3 x 3'
        '4 x 4'
        '5 x 5'
        '6 x 6'
        '7 x 7'
        '8 x 8'
        '9 x 9'
        '10 x 10'
        '11 x 11'
        '12 x 12'
        '13 x 13'
        '14 x 14'
        '15 x 15'
        '16 x 16'
        '17 x 17'
        '18 x 18'
        '19 x 19'
        '20 x 20')
    end
    object IloscIteracjiE: TEdit
      Left = 152
      Top = 48
      Width = 97
      Height = 21
      TabOrder = 1
      Text = '100'
      OnChange = IloscIteracjiEChange
      OnKeyPress = IloscIteracjiEKeyPress
    end
    object IloscIteracjiUD: TUpDown
      Left = 248
      Top = 48
      Width = 17
      Height = 21
      Min = 1
      Max = 1000
      Position = 100
      TabOrder = 2
      OnClick = IloscIteracjiUDClick
    end
    object IloscKanalowUD: TUpDown
      Left = 248
      Top = 75
      Width = 17
      Height = 21
      Min = 1
      Position = 10
      TabOrder = 3
      OnClick = LiczbaKanalowUDClick
    end
    object LiczbaAbonentowUD: TUpDown
      Left = 248
      Top = 102
      Width = 17
      Height = 21
      Min = 1
      Max = 1000
      Position = 200
      TabOrder = 4
      OnClick = LiczbaAbonentowUDClick
    end
    object PrawdRozpRozmUD: TUpDown
      Left = 248
      Top = 129
      Width = 17
      Height = 21
      Min = 1
      Max = 10
      Position = 1
      TabOrder = 5
      OnClick = PrawdRozpRozmUDClick
    end
    object SzerAutostradyUD: TUpDown
      Left = 248
      Top = 156
      Width = 17
      Height = 21
      Min = 10
      Max = 460
      Position = 100
      TabOrder = 6
      OnClick = SzerAutostradyUDClick
    end
    object IloscKanalowE: TEdit
      Left = 152
      Top = 75
      Width = 98
      Height = 21
      TabOrder = 7
      Text = '10'
      OnChange = IloscKanalowEChange
      OnKeyPress = IloscKanalowEKeyPress
    end
    object LiczbaAbonentowE: TEdit
      Left = 152
      Top = 102
      Width = 98
      Height = 21
      TabOrder = 8
      Text = '200'
      OnChange = LiczbaAbonentowEChange
      OnKeyPress = LiczbaAbonentowEKeyPress
    end
    object PrawdRozpRozmE: TEdit
      Left = 152
      Top = 129
      Width = 98
      Height = 21
      TabOrder = 9
      Text = '0,1'
      OnChange = PrawdRozpRozmEChange
      OnKeyPress = PrawdRozpRozmEKeyPress
    end
    object SzerAutostradyE: TEdit
      Left = 152
      Top = 156
      Width = 98
      Height = 21
      TabOrder = 10
      Text = '100'
      OnChange = SzerAutostradyEChange
      OnKeyPress = SzerAutostradyEKeyPress
    end
    object StalaCB: TCheckBox
      Left = 88
      Top = 200
      Width = 97
      Height = 17
      Caption = 'Autostrada Sta'#322'a'
      Checked = True
      State = cbChecked
      TabOrder = 11
    end
    object GroupBox2: TGroupBox
      Left = 3
      Top = 289
      Width = 262
      Height = 160
      Caption = 'Generator liczb pseudolosowych'
      TabOrder = 12
      object CBBZ: TCheckBox
        Left = 16
        Top = 47
        Width = 97
        Height = 17
        Caption = 'Bez ziarna'
        Checked = True
        State = cbChecked
        TabOrder = 0
        OnMouseActivate = CBBZMouseActivate
      end
      object CBZZ: TCheckBox
        Left = 16
        Top = 24
        Width = 97
        Height = 17
        Caption = 'Z ziarnem'
        TabOrder = 1
        OnMouseActivate = CBZZMouseActivate
      end
      object ZiarnoE: TEdit
        Left = 126
        Top = 20
        Width = 108
        Height = 21
        TabOrder = 2
        Text = '1234'
        OnKeyPress = ZiarnoEKeyPress
      end
      object GroupBox4: TGroupBox
        Left = 16
        Top = 70
        Width = 185
        Height = 79
        Caption = 'Rozk'#322'ad normalny'
        TabOrder = 3
        object Label11: TLabel
          Left = 14
          Top = 21
          Width = 53
          Height = 13
          Caption = 'Odchylenie'
        end
        object Label10: TLabel
          Left = 27
          Top = 50
          Width = 36
          Height = 13
          Caption = #346'rednia'
        end
        object OdchylenieE: TEdit
          Left = 103
          Top = 21
          Width = 79
          Height = 21
          TabOrder = 0
          Text = '2'
          OnKeyPress = OdchylenieEKeyPress
        end
        object SredniaE: TEdit
          Left = 103
          Top = 48
          Width = 79
          Height = 21
          TabOrder = 1
          Text = '15'
          OnKeyPress = SredniaEKeyPress
        end
      end
    end
    object ProporcjaTB: TTrackBar
      Left = 3
      Top = 250
      Width = 283
      Height = 33
      Hint = 'Autostrada <- Model -> Statystyczny'
      HelpContext = 1
      Max = 100
      ParentShowHint = False
      Position = 30
      SelEnd = 100
      ShowHint = True
      TabOrder = 13
      OnChange = ProporcjaTBChange
    end
  end
  object StartB: TButton
    Left = 104
    Top = 480
    Width = 75
    Height = 25
    Caption = 'Start'
    TabOrder = 2
    OnClick = StartBClick
  end
  object Zakladki: TTabControl
    Left = 312
    Top = 17
    Width = 644
    Height = 504
    TabOrder = 1
    Tabs.Strings = (
      'Wizualizacja'
      'Wykres'
      'Wyniki')
    TabIndex = 0
    OnChange = ZakladkiChange
    object Image: TImage
      Left = 16
      Top = 29
      Width = 404
      Height = 460
    end
    object Label16: TLabel
      Left = 16
      Top = 29
      Width = 100
      Height = 13
      Caption = 'Przydzia'#322' abonent'#243'w'
      Visible = False
    end
    object Label17: TLabel
      Left = 191
      Top = 29
      Width = 114
      Height = 13
      Caption = 'Rozmawiaj'#261'cy abonenci'
      Visible = False
    end
    object Label18: TLabel
      Left = 367
      Top = 29
      Width = 120
      Height = 13
      Caption = 'Zaj'#281'te kana'#322'y w kom'#243'rce'
      Visible = False
    end
    object Label22: TLabel
      Left = 504
      Top = 29
      Width = 38
      Height = 13
      Caption = 'Iteracja'
    end
    object Label23: TLabel
      Left = 505
      Top = 45
      Width = 3
      Height = 13
    end
    object Wynik: TMemo
      Left = 16
      Top = 48
      Width = 169
      Height = 453
      ScrollBars = ssVertical
      TabOrder = 0
      Visible = False
    end
    object Wynik2: TMemo
      Left = 191
      Top = 48
      Width = 170
      Height = 453
      ScrollBars = ssVertical
      TabOrder = 1
      Visible = False
    end
    object Wykres: TChart
      Left = 3
      Top = 21
      Width = 635
      Height = 480
      BottomWall.Color = clActiveCaption
      LeftWall.Color = clSkyBlue
      Legend.Alignment = laBottom
      Legend.LegendStyle = lsSeries
      Title.Font.Color = clBackground
      Title.Font.Style = [fsBold]
      Title.Text.Strings = (
        'Wykorzystanie wszystkich kana'#322#243'w w czasie')
      BottomAxis.Title.Caption = 'Iteracje'
      LeftAxis.Title.Caption = 'Procent wykorzystania'
      TabOrder = 2
      Visible = False
      PrintMargins = (
        15
        12
        15
        12)
      object Wykorzystanie: TFastLineSeries
        Marks.Callout.Brush.Color = clBlack
        Marks.DrawEvery = 10
        Marks.Visible = True
        Title = 'Wykorzystanie kana'#322#243'w w danej jednostce czasu'
        LinePen.Color = clRed
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
    end
    object PostepPB: TProgressBar
      Left = 505
      Top = 74
      Width = 40
      Height = 332
      Orientation = pbVertical
      TabOrder = 3
    end
    object Wynik3: TMemo
      Left = 367
      Top = 48
      Width = 266
      Height = 453
      ScrollBars = ssVertical
      TabOrder = 4
      Visible = False
    end
  end
  object GroupBox3: TGroupBox
    Left = 738
    Top = 429
    Width = 207
    Height = 77
    Caption = 'Legenda'
    Color = clWhite
    ParentBackground = False
    ParentColor = False
    TabOrder = 3
    object Image1: TImage
      Left = 18
      Top = 24
      Width = 9
      Height = 9
    end
    object Image2: TImage
      Left = 18
      Top = 41
      Width = 9
      Height = 9
    end
    object Image3: TImage
      Left = 18
      Top = 57
      Width = 9
      Height = 9
    end
    object Label19: TLabel
      Left = 37
      Top = 40
      Width = 81
      Height = 13
      Caption = ' - abonent wolny'
    end
    object Label20: TLabel
      Left = 37
      Top = 56
      Width = 125
      Height = 13
      Caption = ' - abonent poza zasi'#281'giem'
    end
    object Label21: TLabel
      Left = 37
      Top = 24
      Width = 118
      Height = 13
      Caption = ' - abonent rozmawiaj'#261'cy'
    end
  end
  object Timer: TTimer
    Enabled = False
    Interval = 100
    OnTimer = TimerTimer
    Left = 248
    Top = 368
  end
  object MainMenu1: TMainMenu
    Left = 248
    Top = 424
    object Symulator1: TMenuItem
      Caption = 'Symulator'
      object Zakocz1: TMenuItem
        Caption = 'Zako'#324'cz'
        OnClick = Zakocz1Click
      end
    end
    object Zapiszwykres1: TMenuItem
      Caption = 'Zapisz wykres'
      OnClick = Zapiszwykres1Click
    end
    object Zapiszdane1: TMenuItem
      Caption = 'Zapisz dane'
      OnClick = Zapiszdane1Click
    end
    object About1: TMenuItem
      Caption = 'About'
      OnClick = About1Click
    end
  end
end
