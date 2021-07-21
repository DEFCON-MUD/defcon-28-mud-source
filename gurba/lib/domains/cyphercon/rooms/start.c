inherit "/std/room";
inherit "/std/menu";

#include "../domain.h"

void setup(void) {

   add_area("required");
   set_short("%^GREEN%^C%^GREY%^y%^HBLUE%^p%^HCYAN%^h%^HGREEN%^e%^HMAGENTA%^r%^HRED%^c%^HWHITE%^o%^MAGENTA%^n %^ORANGE%^C%^RED%^u%^YELLOW%^b%^BLUE%^e%^RESET%^");
   set_coords(({ 0, 0 }));
   set_dimensions(({ 1, 1 }));
   set_mapstart(({ 0, 0} ));

   add_item("cube", "#do_cube");

   set_short("%^GREEN%^C%^GREY%^y%^HBLUE%^p%^HCYAN%^h%^HGREEN%^e%^HMAGENTA%^r%^HRED%^c%^HWHITE%^o%^MAGENTA%^n %^ORANGE%^C%^RED%^u%^YELLOW%^b%^BLUE%^e%^RESET%^");
   set_long("You are in a non descript room, in the center of it floats a 1 inch cube. The cube appears to be glowing and might be speaking to you.");
   set_exits(([
     "east" : "/domains/required/rooms/start"
   ]));

}

static string do_cube(void) {
  object player, obj, to;
  mixed *menu;
  int *cypher_codes;
  int wire, cypher;

  player = this_player();
  to = this_object();
  cypher_codes = player->get_cypher_codes();

  if(!cypher_codes) {
    cypher_codes = (( { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ));
  }

  cypher = cypher_codes[0] + cypher_codes[1] + cypher_codes[2] + cypher_codes[3] + cypher_codes[4] + cypher_codes[5] + cypher_codes[6] + cypher_codes[7] + cypher_codes[8] + cypher_codes[9] + cypher_codes[10] + cypher_codes[11] + cypher_codes[12] + cypher_codes[13] + cypher_codes[14] + cypher_codes[15] + cypher_codes[16] + cypher_codes[17] + cypher_codes[18] + cypher_codes[19] + cypher_codes[20] + cypher_codes[21] + cypher_codes[22] + cypher_codes[23] + cypher_codes[24] + cypher_codes[25] + cypher_codes[26] + cypher_codes[27] + cypher_codes[28] + cypher_codes[29] + cypher_codes[30] + cypher_codes[31];
  wire = cypher_codes[32] + cypher_codes[33] + cypher_codes[34];

  menu = ( { } );

  if(cypher == 32) {
    menu += ({
      ({
         "c", "cypher", nil, make_fcall(to, "do_cypher", nil)
      })
    });
  }

  if(wire == 3) {
    menu += ({
      ({
         "w", "wire", nil, make_fcall(to, "do_wire", nil)
      })
    });
  }

  menu += ({
      ({
         "a", "activate", nil, make_fcall(to, "do_activate", nil)
      })
   });

  menu += ({
      ({
         "q", "quit menu", nil, make_fcall(to, "menu_action_quit")
      })
   });

   do_menu("Sketchy Services:", menu);
   return " ";
}

static int menu_action_quit(void) {
   write("Ok.");
   return 1;
}

int do_activate(string arg) {
  object player, obj, to;
  string CODE1, CODE2, CODE3, CODE4, CODE5, CODE6, CODE7, CODE8, CODE9, CODE10, CODE11, CODE12, CODE13, CODE14, CODE15, CODE16, CODE17, CODE18, CODE19, CODE20, CODE21, CODE22, CODE23, CODE24, CODE25, CODE26, CODE27, CODE28, CODE29, CODE30, CODE31, CODE32;
  int *cypher_codes;
  player = this_player();
  to = this_object();
  cypher_codes = player->get_cypher_codes();

  /* lookup player unlocked tapes */
  if(!cypher_codes) {
    cypher_codes = (( { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ));
  }

  /* set cypher tapes variable to what players have so we can toggle later */



   if (!arg) {
      player->out("Input Cyphercon Tape Code: ");
      player->input_to_object(to, "do_activate");
      return 1;
   }
   if (arg) {
     switch (arg) {
       case "A11CEDD05EDB0BC01D0319":
         write("CODE 1 hit");
         cypher_codes[0] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "A555A11AB1EC1A551C0319":
         write("CODE 2 hit");
         cypher_codes[1] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "D1AB011CA11CD00DAD0319":
         write("CODE 3 hit");
         cypher_codes[2] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "DEC1A551F1EDF11E010319":
         write("CODE 4 hit");
         cypher_codes[3] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "0FF1C1A1CAB1EF11E50319":
         write("CODE 5 hit");
         cypher_codes[4] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "50C1AB1E15ECCC20190319":
         write("CODE 6 hit");
         cypher_codes[5] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "B100D1E5511FEB100D0319":
         write("CODE 7 hit");
         cypher_codes[6] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "BADCE11FEBEDA221ED0319":
         write("CODE 8 hit");
         cypher_codes[7] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "E5CA1A7310CA15A15A0319":
         write("CODE 9 hit");
         cypher_codes[8] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "10ADF11E0FFD15CE0F0319":
         write("CODE 10 hit");
         cypher_codes[9] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "000000000000111ADD0319":
         write("CODE 11 hit");
         cypher_codes[10] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "ADD1EACCE55EDA5C110319":
         write("CODE 12 hit");
         cypher_codes[11] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "DCFEEDB0B0DEADBEEF0319":
         write("CODE 13 hit");
         cypher_codes[12] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "C0FFEE1EADEDD1E5E10319":
         write("CODE 14 hit");
         cypher_codes[13] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "A5C11D1A1ACCE55BBS0319":
         write("CODE 15 hit");
         cypher_codes[14] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "A5C114EA5E0FACCE550319":
         write("CODE 16 hit");
         cypher_codes[15] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "10ADEDDAFF0D11F1F00319":
         write("CODE 17 hit");
         cypher_codes[16] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "E1FEC5AC07AB1EF11E0319":
         write("CODE 18 hit");
         cypher_codes[17] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "BA0BABD10DECAB005E0319":
         write("CODE 19 hit");
         cypher_codes[18] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "B3111AB5BA51CCABA10319":
         write("CODE 20 hit");
         cypher_codes[19] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "0B5E55ED0DDBA11CAD0319":
         write("CODE 21 hit");
         cypher_codes[20] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "5011D1F1ED50DAC0DA0319":
         write("CODE 22 hit");
         cypher_codes[21] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "C0D1F1EDBA5E16B10B0319":
         write("CODE 23 hit");
         cypher_codes[22] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "C0DED15C105ED10CA10319":
         write("CODE 24 hit");
         cypher_codes[23] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "F0551115ED5C51D15C0319":
         write("CODE 25 hit");
         cypher_codes[24] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "1CEFA11F1E1D0FF1CE0319":
         write("CODE 26 hit");
         cypher_codes[25] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "1005E1EAFD15BE11EF0319":
         write("CODE 27 hit");
         cypher_codes[26] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "0551F1EDF1DD1EBACC0319":
         write("CODE 28 hit");
         cypher_codes[27] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "F100DED0A5155EA1ED0319":
         write("CODE 29 hit");
         cypher_codes[28] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "5AFE11FE512E501ACE0319":
         write("CODE 30 hit");
         cypher_codes[29] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "DEC0DE5EEDEDFACADE0319":
         write("CODE 31 hit");
         cypher_codes[30] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "FA151F1AB1E4A111E50319":
         write("CODE 32 hit");
         cypher_codes[31] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "5AFE4F1A7F007F0015":
         write("RESET code hit");
         cypher_codes = (( { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ));
         player->set_cypher_codes(cypher_codes);
         break;
       case "B0B05FACE8BADF00D5":
         write("WIRE CODE 1 hit");
         cypher_codes[32] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "FEADC0ED5CAFEBEEF5":
         write("WIRE CODE 2 hit");
         cypher_codes[33] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       case "0123456789ABCDEF01":
         write("WIRE CODE 3 hit");
         cypher_codes[34] = 1;
         player->set_cypher_codes(cypher_codes);
         break;
       default:
         write("Invalid Code!");
         break;
     }
   }
   player->set_cypher_codes(cypher_codes);
   do_cube();
   return 0;
}

