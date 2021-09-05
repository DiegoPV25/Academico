import os
import time
print("Tower of Power v.1.0.0 ")
print("-Added FX")
print("-Added Music")
print("Maximize this window for better results")
print(" ")
input(">NEW GAME<")
os.system("color 0F")
os.system("cls")
surename= "No"
while surename == "No":
    Pname= input("Please enter your name: ")
    print("")
    print("Name:", Pname, " ")
    print("Is this correct?")
    print(">Yes                >No")
    surename= input("")
    os.system("cls")

import random

DEF=0
def PhoenixFlame(power):
    return (5*power+16+int(random.randrange(10,20)))

def NeedleStorm(power):
    return (10*power + power)

def EnemyAttack():
    return (int(random.randrange(16,36))-int(DEF))

def VoltageVendetta(power):
    return (int(EnemyAttack())*power-power*2)


def BattleSeq():
    player= 1
    enemy= 1
    battle= 1
    y=1

    print("--You confront the",enemyname,"--")
    input("")
    spentsp= int(0)
    DMG=0
    SP= int(30)
    while battle==1:
        print("   --Turn: ",str(y))
        print("   ")
        print("   The",enemyname,"attacked!")
        input()
        os.system("color 48")
        os.system("color 0F")
        os.system("color 48")
        os.system("color 0F")
        os.system("color 48")
        os.system("color 0F")

        if y==1:
            HP= (MaxHP) - int(EnemyAttack())
            DAM= (MaxHP)-HP
            print("   "+Pname+" suffered " + str(DAM) + " hit points of damage")
        else:
            PHP= (HP)
            HP= (PHP) - int(EnemyAttack())
            DAM= (PHP)-HP
            print("   "+Pname+" suffered " + str(DAM) + " hit points of damage")

        print(" ")

        if SP< int(1):
            input("   "+Pname+ " ran out of power and gave up!")
            player=0

        if HP< int(1):
            input("   "+Pname + " collapsed!")
            player=0

        if player==0:
            os.system("color 48")
            print("   Game Over")
            battle=0

        if battle==0:
            break

        print("   ",Pname," HP:", str(HP), "/100")
        print("             SP:", str(SP), "")
        print("")
        print("   Choose an action:")
        print("     >Defend   >Cast   >Attack   >GiveIn")
        act= input("    >")
        DEF=0

        if act== "Cast":
            print("   Cast a spell:")
            print("      >PhoenixFlame   >NeedleStorm   >VoltageVendetta")
            spoll= input("    >")


            if spoll== "PhoenixFlame":
                print("   Power Level?")
                print("   >1       >2      >3")
                print("   -4 SP    -8 SP   -12 SP")
                x = int((input("                                  >")))
                spentsp= int(x)*4
                print( "  ",Pname,"spent",str(spentsp),"trying",spoll,str(x),".")
                os.system("color 48")
                os.system("color 6C")
                os.system("color 48")
                os.system("color 6C")
                os.system("color 48")
                os.system("color 6C")
                os.system("color 48")
                os.system("color 0F")
                DMG= int((PhoenixFlame(x)))

            if spoll== "NeedleStorm":
                print("   Power Level?")
                print("   >1       >2       >3")
                print("   -3 SP    -6 SP    -9 SP")
                x = int((input("                                  >")))
                spentsp= int(x)*3
                print( "  ",Pname,"spent",str(spentsp),"trying",spoll,str(x),".")
                os.system("color 5A")
                os.system("color 0F")
                os.system("color 5A")
                os.system("color 0F")
                os.system("color 5A")
                os.system("color 0F")
                DMG= int((NeedleStorm(x)))



            if spoll== "VoltageVendetta":
                print("   Power Level?")
                print("   >1       >2       >3")
                print("   -6 SP    -12 SP   -18 SP")
                x = int((input("                                  >")))
                spentsp= int(x)*6
                print( "  ",Pname,"spent",str(spentsp),"trying",spoll,str(x),".")
                os.system("color 68")
                os.system("color 0F")
                os.system("color 68")
                os.system("color 0F")
                os.system("color 68")
                os.system("color 0F")
                DMG= int((VoltageVendetta(x)))

            print(Pname,"spent",spentsp,"trying to use",spoll)
            print(spoll,"caused",DMG,"HP of damage to the enemy")


        if act=="Defend":
            HP= MaxHP-int(DAM)+15
            DEF= 10
            DMG= int(0)
            os.system("color 1B")
            print("  ",str(Pname),"stiffened up!")
            print("  ",str(Pname),"will endure next hit")
            spentsp= 0

        if act=="Attack":
            DMG= int(random.randrange(10,35))
            print("  ",Pname,"attacked with all he could!")
            os.system("color 7F")
            os.system("color 0F")
            os.system("color 7F")
            os.system("color 0F")
            os.system("color 7F")
            os.system("color 0F")
            print("   Dealt",str(DMG),"HP of damage to the enemy")
            spentsp= 0

        if act=="GiveIn":
            DMG= int(0)
            print("  ",Pname,"is goofing around...")
            os.system("color 5D")
            input("")
            spentsp= 0

        if y==1:
            HP= MaxHP - int(DAM)
        else:
            HP= PHP - int(DAM)

        SPR= int(random.randrange(2,7))
        SP= SP + SPR
        print("  ",Pname," regained",SPR,"Special Points.")
        input("")

        if y==1:
            EHP= (MaxEHP) - int(DMG)
        else:
            PEHP= EHP
            EHP= (PEHP) - int(DMG)

        SP= (SP) - int(spentsp)
        print("   Enemy HP:", str(EHP), "/115")
        input("")

        if EHP< int(1):
            print("   You won!!!")
            enemy=0
        if enemy==0:
            print("   You won 100 experience points")
            battle=0
        y=(y)+1

enemyname="Slippery Slime"
MaxEHP=115
MaxHP=200
SP= int(30)
BattleSeq()
print("")
os.system("cls")
os.system("color 4F")
enemyname="Brobot"
MaxEHP=150
BattleSeq()
print("")
os.system("cls")
os.system("color 1F")
enemyname="Ghost Ghost"
MaxEHP=200
BattleSeq()
print("")
os.system("cls")
os.system("color 3F")
enemyname="RM-031"
MaxEHP=310
BattleSeq()
print("")
os.system("cls")
os.system("color 2F")
enemyname="Fiery Fiesty Imp"
MaxEHP=667
BattleSeq()
print("")
os.system("cls")
os.system("color 1F")
enemyname="Magiblock"
MaxEHP=1000
BattleSeq()
