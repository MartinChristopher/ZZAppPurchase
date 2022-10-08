//
//  ZZAppPurchase.h
//
//  Created by Apple on 2021/7/2.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>

#pragma mark --------ZZAppPurchaseDelegate--内购代理
/**
 *  内购工具的代理
 */
@protocol ZZAppPurchaseDelegate <NSObject>
@optional;
/**
 *  代理：系统错误
 */
- (void)SysWrong;

/**
 *  代理：已刷新可购买商品
 *
 *  @param products 商品数组
 */
- (void)GotProducts:(NSMutableArray *)products;

/**
 *  代理：购买成功
 *
 *  @param productID 购买成功的商品ID
 */
- (void)BoughtProductSuccessedWithProductID:(NSString *)productID
                                    andInfo:(NSDictionary *)infoDic;;

/**
 *  代理：取消购买
 *
 *  @param productID 商品ID
 */
- (void)CanceldWithProductID:(NSString *)productID;

/**
 *  代理：购买成功，开始验证购买
 *
 *  @param productID 商品ID
 */
- (void)BeginCheckingdWithProductID:(NSString *)productID;

/**
 *  代理：重复验证
 *
 *  @param productID 商品ID
 */
- (void)CheckRedundantWithProductID:(NSString *)productID;

/**
 *  代理：验证失败
 *
 *  @param productID 商品ID
 */
- (void)CheckFailedWithProductID:(NSString *)productID
                         andInfo:(NSData *)infoData;

/**
 *  恢复了已购买的商品（永久性商品）
 *
 *  @param productID 商品ID
 */
- (void)RestoredProductID:(NSString *)productID;


@end

#pragma mark --------ZZAppPurchase--内购工具
/**
 *  内购工具
 */
@interface ZZAppPurchase : NSObject

typedef void(^BoolBlock)(BOOL successed, BOOL result);

typedef void(^DicBlock)(BOOL successed, NSDictionary *result);

/**
 *  代理
 */
@property (nonatomic, weak) id<ZZAppPurchaseDelegate> delegate;

/**
 *  购买完后是否在iOS端向服务器验证一次,默认为YES
 */
@property (nonatomic) BOOL CheckAfterPay;

/**
 *  单例
 *
 *  @return ZZAppPurchase
 */
+ (ZZAppPurchase *)defaultTool;

/**
 *  询问苹果的服务器能够销售哪些商品
 *
 *  @param products 商品ID的数组
 */
- (void)requestProductsWithProductArray:(NSArray *)products;

/**
 *  用户决定购买商品
 *
 *  @param productID 商品ID
 */
- (void)buyProduct:(NSString *)productID;


/**
 *  恢复商品（仅限永久有效商品）
 */
- (void)restorePurchase;

@end
