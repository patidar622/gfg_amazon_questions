public static boolean isWinner(String[][] codeList, String[] shoppingCart) {
        int listIdx = 0, cartIdx = 0;
        
        while(listIdx < codeList.length && cartIdx < shoppingCart.length) {
            int i = cartIdx;

            
            if(codeList[listIdx][0].equals(shoppingCart[i]) || codeList[listIdx][0].equals("anything")) {
                //potential match of code group
                i += 1;
                int j;
                for(j = 1; j < codeList[listIdx].length; j++) {
                    String code = codeList[listIdx][j];
                    String cart = shoppingCart[i];
                    
                    if(!code.equals("anything") && !code.equals(cart)) {
                        break;
                    } else {
                        i++;
                    }
                }
                
                if(j == codeList[listIdx].length) {
                    cartIdx = i;
                    listIdx++;
                } else {
                    cartIdx++;
                }
            } else {
                cartIdx++;
            }
        }
        
        return listIdx == codeList.length;
    }
